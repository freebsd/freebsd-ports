--- ./lib/libxview/win/win_input.c.orig	Sat Apr  1 18:25:30 2000
+++ ./lib/libxview/win/win_input.c	Sat Apr  1 18:25:33 2000
@@ -854,7 +854,9 @@ ContProcess:
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
@@ -862,7 +864,7 @@ ContProcess:
 		    if ((ksym = XLookupKeysym(ek, index)) != NoSymbol)
 			if (IsKeypadKey(ksym)) {
 			    /* See if key has been rebound. */
-			    if (!translate_key(display, ksym, ek->state,
+			    if (translate_key(display, ksym, ek->state,
 					       buffer, BUFFERSIZE)) {
 			        (void)win_translate_KP_keysym(ksym, buffer);
 			    }
@@ -2721,8 +2723,10 @@ win_translate_KP_keysym(keysym, buffer)
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
@@ -2732,11 +2736,18 @@ translate_key(dpy, symbol, modifiers, bu
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
@@ -2762,4 +2773,4 @@ translate_key(dpy, symbol, modifiers, bu
     }
     return 0;
 }
-#endif
+#endif 
