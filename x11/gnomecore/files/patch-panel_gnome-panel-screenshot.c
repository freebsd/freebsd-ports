--- panel/gnome-panel-screenshot.c.orig	Sat Oct  5 13:38:16 2002
+++ panel/gnome-panel-screenshot.c	Sat Oct  5 13:38:51 2002
@@ -53,7 +53,9 @@
 #include <libart_lgpl/art_rgb_affine.h>
 
 #include <stdio.h>
+#ifdef HAVE_LANGINFO_H
 #include <langinfo.h>
+#endif
 
 /* How far down the window tree will we search when looking for top-level
  * windows? Some window managers doubly-reparent the client, so account
