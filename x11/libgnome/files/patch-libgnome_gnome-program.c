--- libgnome/gnome-program.c.orig	Fri Mar 22 11:02:45 2002
+++ libgnome/gnome-program.c	Mon May 20 18:28:24 2002
@@ -882,12 +882,12 @@
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
@@ -899,7 +899,7 @@
     case GNOME_FILE_DOMAIN_HELP:
 	prefix_rel = "/share/gnome/help";
 	attr_name = GNOME_PARAM_GNOME_DATADIR;
-	attr_rel = "/gnome/help";
+	attr_rel = "/help";
 	break;
     case GNOME_FILE_DOMAIN_APP_LIBDIR:
 	prefix_rel = "/lib";
@@ -914,13 +914,13 @@
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
@@ -941,12 +941,12 @@
 
 	attr_name = GNOME_PARAM_APP_DATADIR;
 
-	len = strlen ("/gnome/help/") + 
+	len = strlen ("/help/") + 
 		strlen (program->_priv->app_id) + 1;
 	attr_rel = g_alloca (len);
 	if (attr_rel == NULL /* bad things */)
 		return NULL;
-	g_snprintf (attr_rel, len, "/gnome/help/%s", program->_priv->app_id);
+	g_snprintf (attr_rel, len, "/help/%s", program->_priv->app_id);
 
 	search_path = FALSE;
 	break;
