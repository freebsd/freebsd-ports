--- kitty/colors.c.orig	1979-11-29 23:00:00 UTC
+++ kitty/colors.c
@@ -9,7 +9,7 @@
 #include <structmember.h>
 #include "colors.h"
 #include "color-names.h"
-#ifdef __APPLE__
+#if defined( __APPLE__ ) || defined( __FreeBSD__ )
 // Needed for strod_l
 #include <xlocale.h>
 #endif
