--- inputmethod/ibus/im_ibus.c.orig	2023-04-01 13:54:40 UTC
+++ inputmethod/ibus/im_ibus.c
@@ -1024,7 +1024,7 @@ im_info_t *im_ibus_get_info(char *locale, char *encodi
   }
 
   result->id = strdup("ibus");
-  result->name = strdup("iBus");
+  result->name = strdup("ibus");
   result->num_args = 0;
   result->args = NULL;
   result->readable_args = NULL;
