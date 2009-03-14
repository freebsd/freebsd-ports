--- ./modules/FvwmClean/FvwmClean.c.orig	1994-09-16 15:53:49.000000000 +0000
+++ ./modules/FvwmClean/FvwmClean.c	2009-03-11 09:42:51.000000000 +0000
@@ -52,7 +52,7 @@
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *temp, *s;
   FILE *file;
@@ -134,6 +134,7 @@
   SendInfo(fd,"Send_WindowList",0);
 
   Loop(fd);
+  return (0);
 }
 
 
@@ -228,31 +229,6 @@
 }
 
 
-
-
-/***********************************************************************
- *
- *  Procedure:
- *	safemalloc - mallocs specified space or exits if there's a 
- *		     problem
- *
- ***********************************************************************/
-char *safemalloc(int length)
-{
-  char *ptr;
-  
-  if(length <=0)
-    length = 1;
-
-  ptr = malloc(length);
-  if(ptr == (char *)0)
-    {
-      fprintf(stderr,"%s:malloc failed",MyName);
-      exit(1);
-    }
-  return ptr;
-}
-
 /***********************************************************************
  *
  *  Procedure:
