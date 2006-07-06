--- src/e_mod_main.c.orig	Sat Jun  3 12:35:27 2006
+++ src/e_mod_main.c	Thu Jul  6 23:01:10 2006
@@ -124,7 +124,7 @@
 
    snprintf(title, sizeof(title), "%s %s", D_("Moon Clock Module"), 
 	 PACKAGE_VERSION);
-   e_module_dialog_show(title, 
+   e_module_dialog_show(module, title, 
 	 D_("Display current phase of the moon ala e16 E-MoonClock")); 
    return 1;
 }
