--- libgnome/gnome-program.c.orig	Tue Apr  4 06:55:12 2006
+++ libgnome/gnome-program.c	Mon Apr 10 21:07:02 2006
@@ -936,17 +936,17 @@ gnome_program_locate_file (GnomeProgram 
 	attr_rel = "";
 	break;
     case GNOME_FILE_DOMAIN_DATADIR:
-	prefix_rel = "/share";
+	prefix_rel = "/share/gnome";
 	attr_name = GNOME_PARAM_GNOME_DATADIR;
 	attr_rel = "";
 	break;
     case GNOME_FILE_DOMAIN_SOUND:
-	prefix_rel = "/share/sounds";
+	prefix_rel = "/share/gnome/sounds";
 	attr_name = GNOME_PARAM_GNOME_DATADIR;
 	attr_rel = "/sounds";
 	break;
     case GNOME_FILE_DOMAIN_PIXMAP:
-	prefix_rel = "/share/pixmaps";
+	prefix_rel = "/share/gnome/pixmaps";
 	attr_name = GNOME_PARAM_GNOME_DATADIR;
 	attr_rel = "/pixmaps";
 	break;
@@ -958,7 +958,7 @@ gnome_program_locate_file (GnomeProgram 
     case GNOME_FILE_DOMAIN_HELP:
 	prefix_rel = "/share/gnome/help";
 	attr_name = GNOME_PARAM_GNOME_DATADIR;
-	attr_rel = "/gnome/help";
+	attr_rel = "/help";
 	break;
     case GNOME_FILE_DOMAIN_APP_LIBDIR:
 	prefix_rel = "/lib";
@@ -967,19 +967,19 @@ gnome_program_locate_file (GnomeProgram 
 	search_path = FALSE;
 	break;
     case GNOME_FILE_DOMAIN_APP_DATADIR:
-	prefix_rel = "/share";
+	prefix_rel = "/share/gnome";
 	attr_name = GNOME_PARAM_APP_DATADIR;
 	attr_rel = "";
 	search_path = FALSE;
 	break;
     case GNOME_FILE_DOMAIN_APP_SOUND:
-	prefix_rel = "/share/sounds";
+	prefix_rel = "/share/gnome/sounds";
 	attr_name = GNOME_PARAM_APP_DATADIR;
 	attr_rel = "/sounds";
 	search_path = FALSE;
 	break;
     case GNOME_FILE_DOMAIN_APP_PIXMAP:
-	prefix_rel = "/share/pixmaps";
+	prefix_rel = "/share/gnome/pixmaps";
 	attr_name = GNOME_PARAM_APP_DATADIR;
 	attr_rel = "/pixmaps";
 	search_path = FALSE;
