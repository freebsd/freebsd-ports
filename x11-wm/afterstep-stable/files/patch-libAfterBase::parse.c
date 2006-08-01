$FreeBSD$

--- libAfterBase/parse.c.orig	Thu Jun 22 11:14:06 2006
+++ libAfterBase/parse.c	Thu Jun 22 11:17:46 2006
@@ -690,7 +690,7 @@
 char *
 tokenskip( const char *ptr, unsigned int n_tokens )
 {
-    int    tok_no = 0 ;  ;
+    int    tok_no = 0 ;
     register int  curr = 0 ;
 
     if( ptr == NULL ) return NULL ;
