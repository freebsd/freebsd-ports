--- lib/libxview/win/win_input.c.orig	Sat Aug  6 21:47:27 2005
+++ lib/libxview/win/win_input.c	Sat Aug  6 22:12:06 2005
@@ -853,7 +853,9 @@
 #ifdef X11R6
 	/* lumpi@dobag.in-berlin.de */
 		int ksym_pcc;
-		XGetKeyboardMapping(display,NoSymbol,0,&ksym_pcc);
+		int tc_min_keycode, tc_max_keycode;
+		XDisplayKeycodes(display, &tc_min_keycode, &tc_max_keycode);
+		XGetKeyboardMapping(display,tc_min_keycode,tc_max_keycode-tc_min_keycode-1,&ksym_pcc);
 		for (index = 0; index < ksym_pcc; index++) {
 #else
 		for (index = 0; index < display->keysyms_per_keycode; index++) {
@@ -861,7 +863,7 @@
 		    if ((ksym = XLookupKeysym(ek, index)) != NoSymbol)
 			if (IsKeypadKey(ksym)) {
 			    /* See if key has been rebound. */
-			    if (!translate_key(display, ksym, ek->state,
+			    if (translate_key(display, ksym, ek->state,
 					       buffer, BUFFERSIZE)) {
 			        (void)win_translate_KP_keysym(ksym, buffer);
 			    }
@@ -2311,7 +2313,7 @@
     XButtonEvent   *bEvent;
     int             timeout;
 {
-    XEvent          xevent;
+    XEvent         *xevent;
 
     /* XView does a passive grab on the SELECT button! */
     window_x_allow_events(display);
@@ -2720,8 +2722,10 @@
  * Xlib's.
  */
 
-#ifdef X11R6
-/* lumpi@dobag.in-berlin.de */
+#ifdef X11R6 
+/* lumpi@dobag.in-berlin.de  
+   tom@sees.bangor.ac.uk this replacement for X11R6 doesn't work. At least 
+   it should now return sensible values though. */
 static int
 translate_key(dpy, symbol, modifiers, buffer, nbytes)
     Display 		*dpy;
@@ -2731,11 +2735,18 @@
     int 		 nbytes;
 {
 	/* This is _very_ rude ! */
-	strcpy(buffer,XKeysymToString(symbol));
+	char *string;
+	string = XKeysymToString(symbol);
+     	if (string) {
+		strncpy(buffer,XKeysymToString(symbol),nbytes);
+		return(strlen(buffer));
+	}
+	else
+		return 0;
 }
 
-#else
 
+#else
 static int
 translate_key(dpy, symbol, modifiers, buffer, nbytes)
     Display 		*dpy;
