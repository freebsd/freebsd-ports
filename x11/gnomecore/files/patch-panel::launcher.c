
$FreeBSD$

--- panel/launcher.c	2002/01/22 14:21:27	1.1
+++ panel/launcher.c	2002/01/22 14:21:36
@@ -324,7 +324,7 @@
 			else
 				extension = ".desktop";
 
-			apps_par = g_strconcat ("gnome/apps/", parameters,
+			apps_par = g_strconcat ("apps/", parameters,
 						extension, NULL);
 			entry = gnome_datadir_file (apps_par);
 			g_free (apps_par);
