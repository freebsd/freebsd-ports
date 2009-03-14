--- ./modules/FvwmBacker/FvwmBacker.c.orig	1994-09-28 13:37:39.000000000 +0000
+++ ./modules/FvwmBacker/FvwmBacker.c	2009-03-11 09:42:51.000000000 +0000
@@ -84,7 +84,7 @@
 /* #define LOGFILE "/tmp/FvwmBacker.log"*/
 
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
 char *temp, *s;
 	char*	displayName = NULL;
@@ -139,6 +139,7 @@
 
   /* Recieve all messages from Fvwm */
   EndLessLoop();
+  return (0);
 }
 
 /******************************************************************************
