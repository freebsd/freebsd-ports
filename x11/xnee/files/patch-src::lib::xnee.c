
$FreeBSD$

--- libxnee/src/xnee.c.orig	Tue Apr 29 07:12:42 2003
+++ libxnee/src/xnee.c	Sun May 18 23:09:37 2003
@@ -917,7 +917,7 @@
 xnee_new_xnee_data()
 {
 
-  xnee_data* xd  = (xnee_data*) malloc (sizeof (xnee_data));
+  xnee_data* xd  = (xnee_data*) calloc (1, sizeof (xnee_data));
   if (xd==NULL)
     {
       xnee_print_error ("Could not allocate memory ........\n");
@@ -1230,7 +1230,7 @@
 xnee_use_plugin(xnee_data *xd, char *pl_name)
 {
   int ret=0;
-  xnee_verbose ((xd, "Using plugin file: %s\n", pl_name));
+/*  xnee_verbose ((xd, "Using plugin file: %s\n", pl_name)); */
   
   char lib_name[100];
 
