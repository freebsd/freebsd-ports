--- mpeg2dec/libvo/video_out_x11.c.orig	2006-06-27 01:28:08.000000000 +0600
+++ mpeg2dec/libvo/video_out_x11.c	2008-06-20 18:26:01.000000000 +0600
@@ -531,14 +531,18 @@
     if (window_id == -3) {
       /* display zoomed on the (virtual) root window */
       instance->window = DefaultRootWindow (instance->display);
-      instance->displaywidth = DisplayWidth(instance->display, DefaultScreen (instance->display));
-      instance->displayheight = DisplayHeight(instance->display, DefaultScreen (instance->display));
+      XWindowAttributes xgwa;
+      XGetWindowAttributes (instance->display, instance->window, &xgwa);
+      instance->displaywidth = xgwa.width;
+      instance->displayheight = xgwa.height;
     } else if (window_id == -2) {
       /* display non-zoomed on the (virtual) root window */
       int w, h;
-      w = DisplayWidth(instance->display, DefaultScreen (instance->display));
-      h = DisplayHeight(instance->display, DefaultScreen (instance->display));
       instance->window = DefaultRootWindow (instance->display);
+      XWindowAttributes xgwa;
+      XGetWindowAttributes (instance->display, instance->window, &xgwa);
+      w = xgwa.width;
+      h = xgwa.height;
       instance->corner_x = (w - instance->width)/2;
       instance->corner_y = (h - instance->height)/2;
     } else if (window_id == -1) {
@@ -593,7 +597,9 @@
     /* this would break the solaris port though :-/ */
 
     /* fuck solaris, plug the leak! */
+#ifndef __FreeBSD__
     shmctl(instance->shminfo.shmid, IPC_RMID, 0);
+#endif
 
     /* XShmAttach fails on remote displays, so we have to catch this event */
 
@@ -612,6 +618,9 @@
 	return NULL;
     }
 
+#ifdef __FreeBSD__
+    shmctl(instance->shminfo.shmid, IPC_RMID, 0);
+#endif
     return instance->shminfo.shmaddr;
 }
 
@@ -1006,6 +1015,9 @@
     if (instance == NULL)
 	return NULL;
 
+#ifdef __FreeBSD__
+    memset(instance, 0, sizeof(*instance));
+#endif
     instance->vo.setup = x11_setup;
     return (vo_instance_t *) instance;
 }
@@ -1024,6 +1036,9 @@
     if (instance == NULL)
 	return NULL;
 
+#ifdef __FreeBSD__
+    memset(instance, 0, sizeof(*instance));
+#endif
     instance->vo.setup = xv_setup;
     return (vo_instance_t *) instance;
 }
