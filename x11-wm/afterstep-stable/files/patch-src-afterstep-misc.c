$FreeBSD$

--- src/afterstep/misc.c.orig	2014-04-12 12:28:58.000000000 -0700
+++ src/afterstep/misc.c	2014-04-12 12:29:10.000000000 -0700
@@ -32,13 +32,13 @@
 /****************************************************************************/
 /* window management specifics - button ungrabbing convinience functions:   */
 /****************************************************************************/
-inline void ungrab_window_buttons (Window w)
+void ungrab_window_buttons (Window w)
 {
 	LOCAL_DEBUG_OUT ("w = %lX", w);
 	XUngrabButton (dpy, AnyButton, AnyModifier, w);
 }
 
-inline void ungrab_window_keys (Window w)
+void ungrab_window_keys (Window w)
 {
 	XUngrabKey (dpy, AnyKey, AnyModifier, w);
 }
