--- src/nv-freebsd.h.orig	Wed Oct 30 15:30:58 2002
+++ src/nv-freebsd.h	Thu Mar  6 01:27:10 2003
@@ -27,12 +27,6 @@
  * active development and also unsupported.
  */
 
-#if __FreeBSD_version >= 500000
-#error This driver does not support FreeBSD 5.0/-CURRENT!
-#elif __FreeBSD_version < 470000
-#error This driver requires FreeBSD 4.7 or later!
-#endif
-
 #include <sys/systm.h>
 #include <sys/types.h>
 #include <sys/queue.h>
@@ -86,6 +80,7 @@
 
 #if __FreeBSD_version >= 500000
 #include <sys/mutex.h>
+#include <sys/filedesc.h>
 #include <dev/pci/pcireg.h>
 #include <dev/pci/pcivar.h>
 
@@ -115,6 +110,9 @@
 #define __TD_FDT(td)     ((td)->p_fd)
 #define __TD_FDT_CNT(td) ((td)->p_fd->fd_refcnt)
 
+#define vm_page_lock_queues()
+#define vm_page_unlock_queues()
+
 #endif
 
 /*
@@ -306,7 +304,8 @@
 int    nvidia_open_dev       (struct nvidia_softc *);
 int    nvidia_close_ctl      (dev_t, d_thread_t *);
 int    nvidia_close_dev      (struct nvidia_softc *, dev_t, d_thread_t *);
-int    nvidia_mmap_dev       (struct nvidia_softc *, vm_offset_t);
+int    nvidia_mmap_dev       (struct nvidia_softc *, vm_offset_t,
+    				vm_offset_t *);
 
 #endif /* __NV_FREEBSD_H__ */
 
