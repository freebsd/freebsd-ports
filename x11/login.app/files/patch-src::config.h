--- src/config.h.orig	Sat Jan  8 18:29:31 2005
+++ src/config.h	Sat Jan  8 18:29:45 2005
@@ -23,7 +23,7 @@
 #define CONFIG_H
 
 /* xinit */
-#define XINIT                   "/usr/X11R6/bin/xinit"
+#define XINIT                   "%%X11BASE%%/bin/xinit"
 
 /* Theme directory */
 #define THEME_DIR		"Themes"
