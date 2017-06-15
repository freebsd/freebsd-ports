--- inputmethod/ibus/im_ibus.c.orig	2017-01-07 22:24:38 UTC
+++ inputmethod/ibus/im_ibus.c
@@ -1008,7 +1008,7 @@ im_info_t* im_ibus_get_info(char* locale
   }
 
   result->id = strdup("ibus");
-  result->name = strdup("iBus");
+  result->name = strdup("ibus");
   result->num_of_args = 0;
   result->args = NULL;
   result->readable_args = NULL;
