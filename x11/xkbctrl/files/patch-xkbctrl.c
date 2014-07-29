--- xkbctrl.c.org	Sun Jan  9 22:51:02 2000
+++ xkbctrl.c	Wed Jul  5 22:15:09 2000
@@ -27,7 +27,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <values.h>
+#include <limits.h>
 #include <ctype.h>
 #include <X11/Xos.h>
 #include <X11/Xlib.h>
@@ -112,7 +112,7 @@
 	if (*tmp=='4') {
 	    *changes|= Mod4Mask;
 	    if (onOff)	*mods|= Mod4Mask;
-	    else	*mods&= ~Mod2Mask;
+	    else	*mods&= ~Mod4Mask;
 	}
 	if (*tmp=='5') {
 	    *changes|= Mod5Mask;
