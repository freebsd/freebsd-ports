--- src/nvidia_dev.c.orig	Wed Oct 30 15:30:58 2002
+++ src/nvidia_dev.c	Thu Mar  6 01:09:05 2003
@@ -20,6 +20,7 @@
 static d_mmap_t  nvidia_dev_mmap;
 
 static struct cdevsw nvidia_dev_cdevsw = {
+#if __FreeBSD_version < 500000
     /* open    */  nvidia_dev_open,
     /* close */    nvidia_dev_close,
     /* read */     noread,
@@ -33,10 +34,18 @@
     /* dump */     nodump,
     /* psize */    nopsize,
     /* flags */    D_MEM|D_TRACKCLOSE,
-#if __FreeBSD_version < 500000
     /* bmaj */     -1,
-#endif
     /* kqfilter */ NULL,
+#else
+    .d_open =      nvidia_dev_open,
+    .d_close =     nvidia_dev_close,
+    .d_ioctl =     nvidia_dev_ioctl,
+    .d_poll =      nvidia_dev_poll,
+    .d_mmap =      nvidia_dev_mmap,
+    .d_name =      "nvidia",
+    .d_maj =       CDEV_MAJOR,
+    .d_flags =     D_MEM|D_TRACKCLOSE
+#endif
 };
 
 int nvidia_dev_open(
@@ -135,11 +144,15 @@
 int nvidia_dev_mmap(
     dev_t dev,
     vm_offset_t offset,
+#if __FreeBSD_version >= 500000
+    vm_offset_t *paddr,
+#endif
     int nprot
 )
 {
     nv_state_t *nv;
     struct nvidia_softc *sc;
+    vm_offset_t phys;
 
     int status;
     int unit = minor(dev);
@@ -148,10 +161,17 @@
     nv = sc->nv_state;
 
     nv_lock_api(nv);
-    status = nvidia_mmap_dev(sc, offset);
+    status = nvidia_mmap_dev(sc, offset, &phys);
     nv_unlock_api(nv);
 
+#if __FreeBSD_version >= 500000
+    *paddr = phys;
     return status;
+#else
+    if (status == -1)
+	    return -1;
+    return atop(phys);
+#endif
 }
 
 int nvidia_dev_attach (struct nvidia_softc *sc)
