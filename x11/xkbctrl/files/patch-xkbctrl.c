--- xkbctrl.c.orig	2017-03-09 09:12:29 UTC
+++ xkbctrl.c
@@ -27,7 +27,7 @@ THE USE OR PERFORMANCE OF THIS SOFTWARE.
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <values.h>
+#include <limits.h>
 #include <ctype.h>
 #include <X11/Xos.h>
 #include <X11/Xlib.h>
@@ -112,7 +112,7 @@ register char *tmp;
 	if (*tmp=='4') {
 	    *changes|= Mod4Mask;
 	    if (onOff)	*mods|= Mod4Mask;
-	    else	*mods&= ~Mod2Mask;
+	    else	*mods&= ~Mod4Mask;
 	}
 	if (*tmp=='5') {
 	    *changes|= Mod5Mask;
