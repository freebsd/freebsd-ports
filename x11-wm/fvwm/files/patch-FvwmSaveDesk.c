--- ./modules/FvwmSaveDesk/FvwmSaveDesk.c.orig	1994-09-16 15:07:59.000000000 +0000
+++ ./modules/FvwmSaveDesk/FvwmSaveDesk.c	2009-03-11 09:42:51.000000000 +0000
@@ -64,7 +64,7 @@
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *temp, *s;
   char *display_name = NULL;
@@ -112,6 +112,7 @@
   SendInfo(fd,"Send_WindowList",0);
 
   Loop(fd);
+  return (0);
 }
 
 
