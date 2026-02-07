--- src/main2.c.orig	2011-07-01 09:35:43.000000000 +0200
+++ src/main2.c	2011-07-01 09:35:54.000000000 +0200
@@ -32,7 +32,7 @@
 
 
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   argc = init_display(argc, argv, NULL);    /* setup the display */
   if (argc == 0)
