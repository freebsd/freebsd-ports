--- src/module/e_mod_main.h.orig	Thu Jul 20 00:20:27 2006
+++ src/module/e_mod_main.h	Thu Aug  3 23:24:37 2006
@@ -38,8 +38,9 @@
    E_App       *apps;
    Evas_List   *bars;
    E_Menu      *config_menu;
-   
+
    Config      *conf;
+   E_Module    *module;
 };
 
 struct _Engage_Tray
