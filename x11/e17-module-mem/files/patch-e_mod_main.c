--- e_mod_main.c.orig	Thu Jul  6 22:43:05 2006
+++ e_mod_main.c	Thu Jul  6 22:43:18 2006
@@ -339,7 +339,7 @@
 EAPI int
 e_modapi_about(E_Module *m) 
 {
-   e_module_dialog_show(D_("Enlightenment Mem Monitor Module"), 
+   e_module_dialog_show(m, D_("Enlightenment Mem Monitor Module"), 
 			D_("This module is used to monitor memory."));
    return 1;   
 }
