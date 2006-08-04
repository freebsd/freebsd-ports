--- src/module/e_mod_main.c.orig	Thu Jul 20 00:20:27 2006
+++ src/module/e_mod_main.c	Thu Aug  3 23:24:37 2006
@@ -151,6 +151,7 @@
    /* actually init engage */
    e = _engage_new();
 //   m->config_menu = e->config_menu;
+   e->module = m;
    return e;
 }
 
