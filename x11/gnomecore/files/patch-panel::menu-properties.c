--- panel/menu-properties.c.orig	Sat Jul 13 23:18:06 2002
+++ panel/menu-properties.c	Sat Jul 13 23:18:15 2002
@@ -68,7 +68,7 @@
 		arguments = ".";
 
 	if(strcmp(arguments, ".") == 0)
-		this_menu = gnome_unconditional_datadir_file ("gnome/apps");
+		this_menu = gnome_unconditional_datadir_file ("apps");
 	else if (*arguments == '/')
 		this_menu = g_strdup (arguments);
 	else if (*arguments == '~')
