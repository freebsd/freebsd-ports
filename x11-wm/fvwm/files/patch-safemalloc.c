--- ./libs/safemalloc.c.orig	1994-09-13 19:38:01.000000000 +0000
+++ ./libs/safemalloc.c	2009-03-11 09:42:44.000000000 +0000
@@ -8,15 +8,15 @@
  *		     problem
  *
  ***********************************************************************/
-char *safemalloc(int length)
+void *safemalloc(unsigned int length)
 {
-  char *ptr;
+  void *ptr;
 
   if(length <= 0)
     length = 1;
 
   ptr = malloc(length);
-  if(ptr == (char *)0)
+  if(ptr == NULL)
     {
       fprintf(stderr,"malloc of %d bytes failed. Exiting\n",length);
       exit(1);
