--- inputmethod/ibus/im_ibus.c.orig	2011-05-29 01:07:42.000000000 +0900
+++ inputmethod/ibus/im_ibus.c	2011-05-29 04:57:48.000000000 +0900
@@ -631,7 +631,7 @@
 	}
 
 	result->id = strdup( "ibus") ;
-	result->name = strdup( "iBus") ;
+	result->name = strdup( "ibus") ;
 	result->num_of_args = 0;
 	result->args = NULL ;
 	result->readable_args = NULL ;
