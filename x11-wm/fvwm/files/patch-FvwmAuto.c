--- ./modules/FvwmAuto/FvwmAuto.c.orig	1994-12-02 19:04:02.000000000 +0000
+++ ./modules/FvwmAuto/FvwmAuto.c	2009-03-11 09:42:51.000000000 +0000
@@ -57,7 +57,7 @@
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   FILE *file;
   char mask_mesg[80];
@@ -82,6 +82,7 @@
   sprintf(mask_mesg,"SET_MASK %lu\n",(unsigned long)(M_FOCUS_CHANGE));
   SendInfo(fd,mask_mesg,0);
   Loop(fd);
+  return (0);
 }
 
 
