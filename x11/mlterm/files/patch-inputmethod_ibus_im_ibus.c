--- inputmethod/ibus/im_ibus.c.orig	2011-04-02 11:18:35.000000000 +0900
+++ inputmethod/ibus/im_ibus.c	2011-04-02 11:19:03.000000000 +0900
@@ -627,8 +627,8 @@
 		return  NULL ;
 	}
 
-	result->id = strdup( "iBus") ;
-	result->name = strdup( "iBus") ;
+	result->id = strdup( "ibus") ;
+	result->name = strdup( "ibus") ;
 	result->num_of_args = 0;
 	result->args = NULL ;
 	result->readable_args = NULL ;
