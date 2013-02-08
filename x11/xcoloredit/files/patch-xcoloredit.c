--- xcoloredit.c.orig	Wed May 30 22:10:09 2007
+++ xcoloredit.c	Wed May 30 22:10:57 2007
@@ -38,6 +38,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <X11/Xatom.h>
 #include <X11/X.h>
 #include <X11/Intrinsic.h>
@@ -50,6 +51,7 @@
 #include <X11/Xaw/Form.h>
 #include <X11/Xaw/Box.h>
 #include <X11/Xmu/Atoms.h>
+#include <X11/Xmu/StdSel.h>
 #include "Xcoloredit.h"
 #include "color.h"
 
@@ -85,6 +87,7 @@
 static void move_scroll();
 static void change_text_colour();
 
+static int WhichButton(String name);
 
 #define MEMORY_OFFSET	8
 #define NUM_MEMORIES	36
@@ -182,8 +185,8 @@
 #undef offset
 
 
-void main(argc, argv)
-unsigned int argc;
+int main(argc, argv)
+int argc;
 char **argv;
 {
 	Status ok;
@@ -696,7 +699,7 @@
 								(float)0.025);
 	XawScrollbarSetThumb(valScroll, (float)(1.0 - hsv_values.v),
 								(float)0.025);
-#endif SOLID_THUMB
+#endif /* SOLID_THUMB */
 }
 
 
@@ -878,7 +881,7 @@
 	XawScrollbarSetThumb(w, top, (float)(1.0 - top));
 #else
 	XawScrollbarSetThumb(w, top, (float)0.025);
-#endif SOLID_THUMB
+#endif /* SOLID_THUMB */
 
 	do_change = FALSE;
 	pass_value = 1.0 - rgb_values.r/65536.0;
@@ -941,7 +944,7 @@
 	XawScrollbarSetThumb(w, top, (float)(1.0 - top));
 #else
 	XawScrollbarSetThumb(w, top, (float)0.025);
-#endif SOLID_THUMB
+#endif /* SOLID_THUMB */
 	move_lock();
 }
 
@@ -960,7 +963,7 @@
 						(float)(1.0 - locked_top));
 #else
 	XawScrollbarSetThumb(lockedScroll, locked_top, (float)0.025);
-#endif SOLID_THUMB
+#endif /* SOLID_THUMB */
 }
 
 
@@ -986,8 +989,8 @@
 unsigned long *length;
 int *format;
 {
-	if (XmuConvertStandardSelection(w, selection, target, type, value,
-	    length, format))
+	if (XmuConvertStandardSelection(w, (Time)0, selection, target, type,
+	    (XPointer *)value, length, format))
 		return TRUE;
 
 	if (*target == XA_STRING) {
