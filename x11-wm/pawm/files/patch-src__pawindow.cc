--- src/pawindow.c.orig	Sun Mar  5 10:14:06 2006
+++ src/pawindow.c	Wed Mar  8 13:29:48 2006
@@ -787,10 +787,12 @@
 
 static void canvas_KeyPress(XKeyPressedEvent *event, PAWindow pawindow)
 {
+	XEvent *e;
+
 	ASSERT(event);
 	ASSERT(pawindow);
 
-	XEvent *e = (XEvent *) event;
+	e = (XEvent *) event;
 
 	/* Replay the event if it isn't a pawm keybinding */
 	if (!keyboard_binding_key(event)) {
@@ -1633,6 +1635,7 @@
 	int num_rows=1;
 	int firsticonx, lasticonx, iconx, icony;
 	bool forward= (strcmp((char *)data, "forward")==0 ? 1 : 0);
+  	KeySym testkeysym; KeyCode testkeycode;
 
 
 	/* TODO: Support both rotate method: w/wout popup window*/
@@ -1665,7 +1668,6 @@
                  None, CurrentTime);
 	current_pw=tab_window_draw_all(num_windows, num_rows);
 
-  	KeySym testkeysym; KeyCode testkeycode;
     testkeysym=XStringToKeysym("Tab");
     testkeycode=XKeysymToKeycode(display, testkeysym);
     XGrabKey(display, testkeycode, Mod1Mask, ROOT, False, GrabModeAsync, GrabModeAsync);
