--- gkb-new/preset.c.orig	Fri Mar 14 09:13:44 2003
+++ gkb-new/preset.c	Fri Mar 14 09:13:54 2003
@@ -42,7 +42,7 @@
 
   /* TODO: user's local presets */
 
-  text = gnome_unconditional_datadir_file ("gnome/gkb/");
+  text = gnome_unconditional_datadir_file ("gkb/");
   if (!text)
   	return NULL;
   dir = opendir (text);
