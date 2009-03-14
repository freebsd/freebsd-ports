--- ./modules/FvwmScroll/FvwmScroll.c.orig	1994-09-16 15:08:10.000000000 +0000
+++ ./modules/FvwmScroll/FvwmScroll.c	2009-03-11 09:42:51.000000000 +0000
@@ -65,7 +65,7 @@
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *temp, *s;
   FILE *file;
@@ -159,12 +159,13 @@
     GetTargetWindow(&app_win);
 
   if(app_win == 0)
-    return;
+    return (0);
 
   fd_width = GetFdWidth();
 
   GrabWindow(app_win);
   Loop(app_win);
+  return (0);
 }
 
 
