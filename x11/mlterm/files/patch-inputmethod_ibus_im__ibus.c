--- inputmethod/ibus/im_ibus.c.orig	2016-03-13 10:57:40 UTC
+++ inputmethod/ibus/im_ibus.c
@@ -1289,7 +1289,7 @@ im_ibus_get_info(
 	}
 
 	result->id = strdup( "ibus") ;
-	result->name = strdup( "iBus") ;
+	result->name = strdup( "ibus") ;
 	result->num_of_args = 0;
 	result->args = NULL ;
 	result->readable_args = NULL ;
