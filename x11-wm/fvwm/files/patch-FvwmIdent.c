--- ./modules/FvwmIdent/FvwmIdent.c.orig	1994-09-16 15:07:11.000000000 +0000
+++ ./modules/FvwmIdent/FvwmIdent.c	2009-03-11 09:42:51.000000000 +0000
@@ -80,7 +80,7 @@
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *temp, *s;
   FILE *file;
@@ -173,6 +173,7 @@
   SendInfo(fd,"Send_WindowList",0);
 
   Loop(fd);
+  return (0);
 }
 
 /**************************************************************************
