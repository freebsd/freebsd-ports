--- src/nvidia-modeset/nvidia-modeset-freebsd.c.orig	2024-03-11 15:49:45 UTC
+++ src/nvidia-modeset/nvidia-modeset-freebsd.c
@@ -27,6 +27,7 @@
 #include <sys/file.h>
 #include <sys/proc.h>
 #include <sys/stack.h>
+#include <sys/sysproto.h>
 
 #include "nvkms-ioctl.h"
 #include "nvidia-modeset-os-interface.h"
@@ -52,6 +53,7 @@
     #include "machine/../linux32/linux32_proto.h"
   #endif
   #include <compat/linux/linux_ioctl.h>
+  #include <compat/linux/linux_util.h>
 #endif
 
 
@@ -280,7 +282,12 @@ struct nvkms_ref_ptr* nvkms_alloc_ref_ptr(void *ptr)
 
 struct nvkms_ref_ptr* nvkms_alloc_ref_ptr(void *ptr)
 {
-    struct nvkms_ref_ptr *ref_ptr = nvkms_alloc(sizeof(*ref_ptr), NV_FALSE);
+    /*
+     * Initialize memory to avoid spurious "lock re-initialization" errors.
+     * A little more detail can be found in the PR 201340 starting around
+     * comment #50.
+     */
+    struct nvkms_ref_ptr *ref_ptr = nvkms_alloc(sizeof(*ref_ptr), NV_TRUE);
     if (ref_ptr) {
         mtx_init(&ref_ptr->lock, "nvkms-ref-ptr-lock", NULL, MTX_SPIN);
         // The ref_ptr owner counts as a reference on the ref_ptr itself.
@@ -371,7 +378,7 @@ static struct {
  * Global list with pending timers, any change requires acquiring lock
  */
 static struct {
-    struct sx lock;
+    struct mtx lock;
     LIST_HEAD(nvkms_timers_head, nvkms_timer_t) list;
 } nvkms_timers;
 
@@ -384,9 +391,9 @@ static void nvkms_taskqueue_callback(void *arg, int pe
      * We can delete this timer from pending timers list - it's being
      * processed now.
      */
-    sx_xlock(&nvkms_timers.lock);
+    mtx_lock_spin(&nvkms_timers.lock);
     LIST_REMOVE(timer, timers_list);
-    sx_xunlock(&nvkms_timers.lock);
+    mtx_unlock_spin(&nvkms_timers.lock);
 
     /*
      * After taskqueue_callback we want to be sure that callout_callback
@@ -454,7 +461,7 @@ nvkms_init_timer(struct nvkms_timer_t *timer, nvkms_ti
      * run in parallel with this, it could race against nvkms_init_timer()
      * and free the timer before its initialization is complete.
      */
-    sx_xlock(&nvkms_timers.lock);
+    mtx_lock_spin(&nvkms_timers.lock);
     LIST_INSERT_HEAD(&nvkms_timers.list, timer, timers_list);
 
     if (usec == 0) {
@@ -468,7 +475,7 @@ nvkms_init_timer(struct nvkms_timer_t *timer, nvkms_ti
                       NVKMS_USECS_TO_TICKS(usec),
                       nvkms_callout_callback, (void *) timer);
     }
-    sx_xunlock(&nvkms_timers.lock);
+    mtx_unlock_spin(&nvkms_timers.lock);
 }
 
 nvkms_timer_handle_t*
@@ -916,29 +923,31 @@ static int nvkms_poll(
  *************************************************************************/
 
 #if defined(NVKMS_SUPPORT_LINUX_COMPAT)
+static struct linux_device_handler nvkms_linux_device_handler = {
+    .bsd_driver_name = "nvidia-modeset",
+    .linux_driver_name = "nvidia-modeset",
+    .bsd_device_name = "nvidia-modeset",
+    .linux_device_name = "nvidia-modeset",
+    .linux_major = 195,
+    .linux_minor = 254,
+    .linux_char_device = 1
+};
 
 static int nvkms_linux_ioctl_function(
     struct thread *td,
     struct linux_ioctl_args *args
 )
 {
-    struct file *fp;
-    int status;
-    u_long cmd;
+    static const uint32_t dir[4] = { IOC_VOID, IOC_IN, IOC_OUT, IOC_INOUT };
 
-    cap_rights_t rights;
-    status = fget(td, args->fd, cap_rights_init(&rights, CAP_IOCTL), &fp);
-
-    if (status != 0) {
-        return status;
+    if ((args->cmd & (1<<29)) != 0) {
+        /* FreeBSD has only 13 bits to encode the size. */
+        printf("nvidia: pid %d (%s): ioctl cmd=0x%x size too large\n",
+            (int)td->td_proc->p_pid, td->td_proc->p_comm, args->cmd);
+        return (EINVAL);
     }
-
-    cmd = args->cmd;
-
-    status = fo_ioctl(fp, cmd, (caddr_t)args->arg, td->td_ucred, td);
-    fdrop(fp, td);
-
-    return status;
+    args->cmd = (args->cmd & ~IOC_DIRMASK) | dir[args->cmd >> 30];
+    return (sys_ioctl(td, (struct ioctl_args *)args));
 }
 
 #define NVKMS_LINUX_IOCTL_MIN _IOC(0, NVKMS_IOCTL_MAGIC, NVKMS_IOCTL_CMD, 0)
@@ -954,6 +963,7 @@ static void nvkms_linux_compat_load(void)
 static void nvkms_linux_compat_load(void)
 {
 #if defined(NVKMS_SUPPORT_LINUX_COMPAT)
+    linux_device_register_handler(&nvkms_linux_device_handler);
     linux_ioctl_register_handler(&nvkms_linux_ioctl_handler);
 #endif
 }
@@ -962,6 +972,7 @@ static void nvkms_linux_compat_unload(void)
 {
 #if defined(NVKMS_SUPPORT_LINUX_COMPAT)
     linux_ioctl_unregister_handler(&nvkms_linux_ioctl_handler);
+    linux_device_unregister_handler(&nvkms_linux_device_handler);
 #endif
 }
 
@@ -1011,7 +1022,7 @@ nvidia_modeset_loader(struct module *m, int what, void
         nvkms_module.is_unloading = NV_FALSE;
 
         LIST_INIT(&nvkms_timers.list);
-        sx_init(&nvkms_timers.lock, "nvidia-modeset timer lock");
+        mtx_init(&nvkms_timers.lock, "nvidia-modeset timer lock", NULL, MTX_SPIN);
 
         nvkms_dev = make_dev(&nvkms_cdevsw,
                              NVKMS_CDEV_MINOR,
@@ -1020,7 +1031,7 @@ nvidia_modeset_loader(struct module *m, int what, void
 
         if (nvkms_dev == NULL) {
             sx_destroy(&nvkms_module.lock);
-            sx_destroy(&nvkms_timers.lock);
+            mtx_destroy(&nvkms_timers.lock);
             sx_destroy(&nvkms_lock);
 
             nvkms_free_rm();
@@ -1089,7 +1100,7 @@ nvidia_modeset_loader(struct module *m, int what, void
          * nvkms_taskqueue_callback() doesn't get called after the
          * module is unloaded.
          */
-        sx_xlock(&nvkms_timers.lock);
+        mtx_lock_spin(&nvkms_timers.lock);
 
         LIST_FOREACH_SAFE(timer, &nvkms_timers.list, timers_list, tmp) {
             if (timer->callout_created) {
@@ -1111,7 +1122,7 @@ nvidia_modeset_loader(struct module *m, int what, void
             }
         }
 
-        sx_xunlock(&nvkms_timers.lock);
+        mtx_unlock_spin(&nvkms_timers.lock);
 
         taskqueue_run(taskqueue_nvkms);
 
@@ -1119,7 +1130,7 @@ nvidia_modeset_loader(struct module *m, int what, void
         nvkms_dev = NULL;
 
         sx_destroy(&nvkms_module.lock);
-        sx_destroy(&nvkms_timers.lock);
+        mtx_destroy(&nvkms_timers.lock);
         sx_destroy(&nvkms_lock);
 
         nvkms_free_rm();
@@ -1151,4 +1162,9 @@ MODULE_DEPEND(nvidia_modeset,               /* module 
 MODULE_DEPEND(nvidia_modeset,               /* module name */
               linux,                        /* prerequisite module */
               1, 1, 1);                     /* vmin, vpref, vmax */
+#if defined(NVCPU_X86_64)
+MODULE_DEPEND(nvidia_modeset,               /* module name */
+              linux_common,                 /* prerequisite module */
+              1, 1, 1);                     /* vmin, vpref, vmax */
+#endif
 #endif
