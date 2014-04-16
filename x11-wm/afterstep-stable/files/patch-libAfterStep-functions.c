$FreeBSD$

--- libAfterStep/functions.c.orig	2014-04-12 10:22:40.000000000 -0700
+++ libAfterStep/functions.c	2014-04-11 06:32:05.000000000 -0700
@@ -307,7 +307,7 @@
 	}
 }
 
-inline FunctionData *create_named_function (int func, char *name)
+FunctionData *create_named_function (int func, char *name)
 {
 	FunctionData *fdata = safecalloc (1, sizeof (FunctionData));
 
