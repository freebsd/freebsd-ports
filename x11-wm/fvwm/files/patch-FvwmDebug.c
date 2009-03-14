--- ./modules/FvwmDebug/FvwmDebug.c.orig	1994-09-30 12:48:59.000000000 +0000
+++ ./modules/FvwmDebug/FvwmDebug.c	2009-03-11 09:42:51.000000000 +0000
@@ -36,7 +36,7 @@
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *temp, *s;
 
@@ -75,6 +75,7 @@
   SendInfo(fd,"Send_WindowList",0);
 
   Loop(fd);
+  return (0);
 }
 
 /***********************************************************************
