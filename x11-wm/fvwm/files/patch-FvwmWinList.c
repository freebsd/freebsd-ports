--- ./modules/FvwmWinList/FvwmWinList.c.orig	1994-09-19 12:40:13.000000000 +0000
+++ ./modules/FvwmWinList/FvwmWinList.c	2009-03-11 09:42:51.000000000 +0000
@@ -101,7 +101,7 @@
     Based on main() from FvwmIdent:
       Copyright 1994, Robert Nation and Nobutaka Suzuki.
 ******************************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
 char *temp, *s;
 
@@ -153,6 +153,7 @@
 
   /* Recieve all messages from Fvwm */
   EndLessLoop();
+  return (0);
 }
 
 /******************************************************************************
