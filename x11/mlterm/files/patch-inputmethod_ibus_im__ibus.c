--- inputmethod/ibus/im_ibus.c.orig	2017-12-02 16:03:23 UTC
+++ inputmethod/ibus/im_ibus.c
@@ -1033,7 +1033,7 @@ im_info_t *im_ibus_get_info(char *locale
   }
 
   result->id = strdup("ibus");
-  result->name = strdup("iBus");
+  result->name = strdup("ibus");
   result->num_args = 0;
   result->args = NULL;
   result->readable_args = NULL;
