--- xlock/resource.c.orig	Wed Dec  3 05:10:59 2003
+++ xlock/resource.c	Mon Jan 19 19:16:54 2004
@@ -166,7 +166,7 @@
 #endif
 #define DEF_PLANFONT     "-adobe-courier-medium-r-*-*-14-*-*-*-m-*-iso8859-1"
 #ifdef USE_MB
-# define DEF_FONTSET	DEF_FONT ## ",-*-*-medium-r-normal--24-*"
+# define DEF_FONTSET	DEF_FONT ",-*-*-medium-r-normal--24-*"
 #endif /* USE MB */
 #define DEF_BG		"White"
 #define DEF_FG		"Black"
