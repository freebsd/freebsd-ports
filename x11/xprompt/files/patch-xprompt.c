--- ./xprompt.c.orig	1995-08-07 18:25:13.000000000 +0000
+++ ./xprompt.c	2013-06-02 08:18:31.000000000 +0000
@@ -387,7 +387,7 @@
 void unparsegeometry();
 
 main(argc, argv)
-unsigned int argc;
+int argc;
 char **argv;
 {
     register int i, j;
