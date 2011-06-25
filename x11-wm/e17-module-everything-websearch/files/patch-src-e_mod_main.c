--- src/e_mod_main.c.orig	2011-01-29 15:40:21.202964309 +0100
+++ src/e_mod_main.c	2011-01-29 15:40:36.482221909 +0100
@@ -216,7 +216,7 @@
 
    ecore_con_url_url_set(dd->con_url, url);
 
-   return ecore_con_url_get(dd->con_url, NULL, 0, NULL);
+   return ecore_con_url_get(dd->con_url);
 }
 
 static Eina_Bool
