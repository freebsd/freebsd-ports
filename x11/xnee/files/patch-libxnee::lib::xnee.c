--- libxnee/src/xnee.c.orig	Sun Sep 28 07:58:48 2003
+++ libxnee/src/xnee.c	Tue Nov  4 10:36:43 2003
@@ -572,7 +572,7 @@
 xnee_new_xnee_data()
 {
 
-  xnee_data* xd  = (xnee_data*) malloc (sizeof (xnee_data));
+  xnee_data* xd  = (xnee_data*) calloc (1, sizeof (xnee_data));
   if (xd==NULL)
     {
       xnee_print_error ("Could not allocate memory ........\n");
@@ -908,7 +908,7 @@
   int ret=0;
   char lib_name[100];
 
-  xnee_verbose ((xd, "Using plugin file: %s\n", pl_name));
+/*  xnee_verbose ((xd, "Using plugin file: %s\n", pl_name)); */
   strcpy (lib_name, "lib");
   strcat (lib_name, pl_name);
   
