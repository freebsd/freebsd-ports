
$FreeBSD$

--- src/lib/xnee.c.orig	Sun Feb  9 21:17:05 2003
+++ src/lib/xnee.c	Sun Feb  9 21:18:44 2003
@@ -501,7 +501,11 @@
   int ret;
   int window;
   int screen;
-  
+
+  if (xd->grab==NULL)
+    {
+      xd->grab = XOpenDisplay (NULL);
+    }
   screen = DefaultScreen (xd->grab);
   window = RootWindow(xd->grab, screen );
   xnee_verbose (xd, "window   %d\n", window);
@@ -696,7 +700,7 @@
 xnee_new_xnee_data()
 {
 
-  xnee_data* xd  = (xnee_data*) malloc (sizeof (xnee_data));
+  xnee_data* xd  = (xnee_data*) calloc (1, sizeof (xnee_data));
   if (xd==NULL)
     {
       xnee_print_error ("Could not allocate memory ........\n");
