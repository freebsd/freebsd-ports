
$FreeBSD$

--- src/lib/xnee.c.orig	Wed Mar 19 08:01:11 2003
+++ src/lib/xnee.c	Fri Apr 18 16:51:11 2003
@@ -881,7 +881,7 @@
 xnee_new_xnee_data()
 {
 
-  xnee_data* xd  = (xnee_data*) malloc (sizeof (xnee_data));
+  xnee_data* xd  = (xnee_data*) calloc (1, sizeof (xnee_data));
   if (xd==NULL)
     {
       xnee_print_error ("Could not allocate memory ........\n");
