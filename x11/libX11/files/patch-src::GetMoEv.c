--- src/GetMoEv.c.orig	Thu Jun 21 19:45:32 2007
+++ src/GetMoEv.c	Thu Jun 21 19:45:45 2007
@@ -33,9 +33,9 @@
 
 XTimeCoord *XGetMotionEvents(
     register Display *dpy,
+    Window w,
     Time start, 
     Time stop,
-    Window w,
     int *nEvents)  /* RETURN */
 {       
     xGetMotionEventsReply rep;
