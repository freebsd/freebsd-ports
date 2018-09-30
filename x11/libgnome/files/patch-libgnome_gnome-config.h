--- libgnome/gnome-config.h.orig	2009-04-23 09:29:13 UTC
+++ libgnome/gnome-config.h
@@ -270,7 +270,7 @@ void gnome_config_clean_key_ (const char *path, gboole
 #define gnome_config_private_clean_key(path) \
 	(gnome_config_clean_key_((path),TRUE))
 
-/* returns the true filename of the config file */
+/* returns the true filename of the config file */
 #define gnome_config_get_real_path(path) \
 	(g_build_filename (gnome_user_dir_get(),(path),NULL))
 #define gnome_config_private_get_real_path(path) \
