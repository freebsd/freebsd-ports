
$FreeBSD$

--- panel/main.c.orig	Sat Jun  8 01:37:03 2002
+++ panel/main.c	Mon Jun 10 15:23:57 2002
@@ -386,7 +386,7 @@
 {
 	int len;
 
-	merge_main_dir = gnome_datadir_file("gnome/apps");
+	merge_main_dir = gnome_datadir_file("apps");
 	merge_main_dir_len = merge_main_dir != NULL ? strlen (merge_main_dir) : 0;
 	merge_merge_dir = conditional_get_string ("/panel/Merge/Directory",
 						  "/etc/X11/applnk/",
