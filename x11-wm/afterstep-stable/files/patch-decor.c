$FreeBSD$

--- libAfterStep/decor.c.orig	Fri Apr  1 10:55:09 2005
+++ libAfterStep/decor.c	Fri Apr  1 10:55:38 2005
@@ -1659,8 +1659,8 @@
 void
 on_astbar_pointer_action( ASTBarData *tbar, int context, Bool leave, Bool pointer_moved )
 {
-    LOCAL_DEBUG_CALLER_OUT( "%p, %s, %d", tbar, context2text(context), leave );
 	static ASBalloon *last_balloon = NULL ;
+    LOCAL_DEBUG_CALLER_OUT( "%p, %s, %d", tbar, context2text(context), leave );
     
 	if( tbar == NULL )
     {
