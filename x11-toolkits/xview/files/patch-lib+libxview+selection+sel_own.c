--- ./lib/libxview/selection/sel_own.c.orig	Sun Jun 26 03:05:22 1994
+++ ./lib/libxview/selection/sel_own.c	Sat Apr  1 18:25:28 2000
@@ -35,6 +35,7 @@ static int SelLoseOwnership();
 static int sel_set_ownership(/* sel_owner */);
 static int (*OldErrorHandler)();
 static int SelOwnerErrorHandler();
+static int SendIncr();
 static int ValidatePropertyEvent();
 
 static void SelClean();
