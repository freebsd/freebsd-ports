--- ./modules/FvwmPager/FvwmPager.c.orig	1994-10-07 12:49:26.000000000 +0000
+++ ./modules/FvwmPager/FvwmPager.c	2009-03-11 09:42:51.000000000 +0000
@@ -82,7 +82,7 @@
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *temp, *s, *cptr;
   char *display_name = NULL;
@@ -186,6 +186,7 @@
   SendInfo(fd,"Send_WindowList",0);
   
   Loop(fd);
+  return (0);
 }
 
 /***********************************************************************
