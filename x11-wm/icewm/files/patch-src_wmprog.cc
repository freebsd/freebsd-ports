--- src/wmprog.cc.orig	Mon Jan 15 06:49:41 2001
+++ src/wmprog.cc	Mon Jan 15 22:18:07 2001
@@ -474,7 +474,7 @@
 
 #ifdef GNOME
     if (autoReloadMenus) {
-        char *gnomeAppsMenu = gnome_datadir_file("gnome/apps/");
+        char *gnomeAppsMenu = gnome_datadir_file("apps/");
         char *gnomeUserMenu = gnome_util_home_file("apps/");
         const char *kdeMenu = strJoin(kdeDataDir, "/applnk", 0);
 
@@ -535,7 +535,7 @@
         YIcon *gnomeicon = 0;
         YIcon *kdeicon = 0;
 
-        char *gnomeAppsMenu = gnome_datadir_file("gnome/apps/");
+        char *gnomeAppsMenu = gnome_datadir_file("apps/");
         char *gnomeUserMenu = gnome_util_home_file("apps/");
         const char *kdeMenu = strJoin(kdeDataDir, "/applnk", 0);
