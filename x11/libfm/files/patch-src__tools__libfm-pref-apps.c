--- ./src/tools/libfm-pref-apps.c.orig	2012-03-18 14:21:22.000000000 +1030
+++ ./src/tools/libfm-pref-apps.c	2012-03-18 14:22:13.000000000 +1030
@@ -38,7 +38,7 @@
 static GList* mail_clients = NULL;
 
 /* examine desktop files under Internet and Office submenus to find out browsers and mail clients */
-static init_apps()
+static void init_apps()
 {
     MenuCache* mc = menu_cache_lookup_sync("applications.menu");
     MenuCacheDir* dir;
