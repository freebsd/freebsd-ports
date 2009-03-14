--- ./modules/FvwmIconBox/FvwmIconBox.c.orig	1994-09-16 15:54:49.000000000 +0000
+++ ./modules/FvwmIconBox/FvwmIconBox.c	2009-03-11 09:42:51.000000000 +0000
@@ -155,7 +155,7 @@
   Based on main() from GoodStuff:
   	Copyright 1993, Robert Nation.
 ************************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *display_name = NULL;
   char *temp, *s;
@@ -223,6 +223,7 @@
   SendFvwmPipe(fd,"Send_WindowList",0);
 
   Loop();
+  return (0);
 }
 
 /************************************************************************
