--- src/e_mod_main.c.orig	Thu Jul  6 23:11:37 2006
+++ src/e_mod_main.c	Thu Jul  6 23:13:48 2006
@@ -47,7 +47,7 @@
       
      {
         e_error_dialog_show 
-           ("Module API Error", "Error initializing Module: calendar\n" 
+           (module, "Module API Error", "Error initializing Module: calendar\n" 
             "It requires a minimum module API version of: %i.\n" 
             "The module API advertized by Enlightenment is: %i.\n" 
             "Aborting module.", E_MODULE_API_VERSION, module->api->version);
@@ -102,7 +102,7 @@
 EAPI int 
 e_modapi_about(E_Module *module) 
 {
-   e_error_dialog_show(D_("Enlightenment calendar Module"), D_("A simple module to give E17 a desktop calendar "));
+   e_error_dialog_show(module, D_("Enlightenment calendar Module"), D_("A simple module to give E17 a desktop calendar "));
    return 1;
 }
 
