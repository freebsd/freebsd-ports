--- libgnome/gnome-program.c.orig	Mon Feb 21 07:39:01 2005
+++ libgnome/gnome-program.c	Mon Feb 21 23:35:17 2005
@@ -895,17 +895,17 @@
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
@@ -917,7 +917,7 @@
     case GNOME_FILE_DOMAIN_HELP:
 	prefix_rel = "/share/gnome/help";
 	attr_name = GNOME_PARAM_GNOME_DATADIR;
-	attr_rel = "/gnome/help";
+	attr_rel = "/help";
 	break;
     case GNOME_FILE_DOMAIN_APP_LIBDIR:
 	prefix_rel = "/lib";
@@ -926,19 +926,19 @@
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
@@ -959,12 +959,12 @@
 
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
@@ -1928,7 +1928,7 @@
                            int argc, char **argv,
                            guint nparams, GParameter *params)
 {
-    va_list args = 0;
+    va_list args;
 
     return gnome_program_init_common (type, app_id, app_version, module_info,
 				      argc, argv, NULL, args, nparams, params);
