--- ./fvwm/fvwm.c.orig	1994-11-15 14:02:52.000000000 +0000
+++ ./fvwm/fvwm.c	2009-03-11 09:42:51.000000000 +0000
@@ -132,7 +132,7 @@
  *
  ***********************************************************************
  */
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     unsigned long valuemask;	/* mask for create windows */
     XSetWindowAttributes attributes;	/* attributes for create windows */
@@ -463,7 +463,7 @@
       }
 
     HandleEvents();
-    return;
+    return (0);
 }
 
 /***********************************************************************
@@ -988,6 +988,7 @@
 #endif
 
   fprintf(stderr,USAGE,VERSION);
+  exit (0);
 
 }
 
