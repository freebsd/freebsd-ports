--- kb2mb2.c.orig	Thu Aug 23 00:07:17 2001
+++ kb2mb2.c	Thu Aug 23 00:17:02 2001
@@ -165,7 +165,9 @@
 	    if (verbose) {
 		fprintf(stderr, "Pressed Key %x\n", input_keysym);
 	    }
-	    XTestFakeButtonEvent(d, Button2, True, CurrentTime);
+	    if (input_keycode == keycode) {
+	        XTestFakeButtonEvent(d, Button2, True, CurrentTime);
+	    }
 	    break;
 	  case KeyRelease:
 	    input_keycode = ev.xkey.keycode;
@@ -174,7 +176,9 @@
 	    if (verbose) {
 		fprintf(stderr, "Released Key %x\n", input_keysym);
 	    }
-	    XTestFakeButtonEvent(d, Button2, False, CurrentTime);
+	    if (input_keycode == keycode) {
+	        XTestFakeButtonEvent(d, Button2, False, CurrentTime);
+	    }
 	    break;
 	}
 	XFlush(d);
