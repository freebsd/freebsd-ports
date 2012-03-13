--- ./src/gui/image/qnativeimage.cpp.orig	2012-03-12 13:30:21.000000000 +0100
+++ ./src/gui/image/qnativeimage.cpp	2012-03-12 13:32:39.000000000 +0100
@@ -178,15 +178,17 @@
     if (ok) {
         xshmimg->data = (char*)shmat(xshminfo.shmid, 0, 0);
         xshminfo.shmaddr = xshmimg->data;
-        if (shmctl(xshminfo.shmid, IPC_RMID, 0) == -1)
-            qWarning() << "Error while marking the shared memory segment to be destroyed";
         ok = (xshminfo.shmaddr != (char*)-1);
         if (ok)
             image = QImage((uchar *)xshmimg->data, width, height, format);
     }
     xshminfo.readOnly = false;
-    if (ok)
+    if (ok) {
         ok = XShmAttach(X11->display, &xshminfo);
+        XSync(X11->display, False);
+        if (shmctl(xshminfo.shmid, IPC_RMID, 0) == -1)
+            qWarning() << "Error while marking the shared memory segment to be destroyed";
+    }
     if (!ok) {
         qWarning() << "QNativeImage: Unable to attach to shared memory segment.";
         if (xshmimg->data) {
