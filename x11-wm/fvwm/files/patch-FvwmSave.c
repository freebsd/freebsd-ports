--- ./modules/FvwmSave/FvwmSave.c.orig	1994-09-16 15:07:40.000000000 +0000
+++ ./modules/FvwmSave/FvwmSave.c	2009-03-11 09:42:51.000000000 +0000
@@ -51,7 +51,7 @@
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *temp, *s;
   char *display_name = NULL;
@@ -99,6 +99,7 @@
   SendInfo(fd,"Send_WindowList",0);
 
   Loop(fd);
+  return (0);
 }
 
 
