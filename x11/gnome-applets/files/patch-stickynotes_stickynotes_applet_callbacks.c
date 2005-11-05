--- stickynotes/stickynotes_applet_callbacks.c.orig	Wed Jul 13 18:57:03 2005
+++ stickynotes/stickynotes_applet_callbacks.c	Wed Jul 13 18:57:13 2005
@@ -153,6 +153,7 @@ gboolean applet_check_click_on_desktop_c
 {
 	static Window desktop_window = 0;
 	static Display *dpy;
+	XEvent event;
 
 	if (desktop_window == 0) {
 		desktop_window = get_desktop_window ();
@@ -162,7 +163,6 @@ gboolean applet_check_click_on_desktop_c
                  * at every click on the desktop */
 		XSelectInput(dpy, desktop_window, PropertyChangeMask);
 	}
-	XEvent event;
 
 	if (XCheckWindowEvent(dpy, desktop_window, PropertyChangeMask, &event) == True) {
 		stickynote_show_notes (FALSE);
