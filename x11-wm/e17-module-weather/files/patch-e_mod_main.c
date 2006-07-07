--- e_mod_main.c.orig	Thu Jul  6 23:05:04 2006
+++ e_mod_main.c	Thu Jul  6 23:05:19 2006
@@ -354,7 +354,8 @@
 EAPI int
 e_modapi_about(E_Module *m)
 {
-   e_module_dialog_show(D_("Enlightenment Weather Module"), D_("A weather forecast module for Enlightenment"));
+   e_module_dialog_show(m, D_("Enlightenment Weather Module"), 
+	D_("A weather forecast module for Enlightenment"));
    return 1;
 }
 
