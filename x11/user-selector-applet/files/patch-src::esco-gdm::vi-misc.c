--- src/esco-gdm/ve-misc.c.orig	Sat May  8 23:13:22 2004
+++ src/esco-gdm/ve-misc.c	Sat May  8 23:23:40 2004
@@ -431,13 +431,13 @@
  * of environment.
  * 
  **/
+extern char **environ;
 void
 ve_clearenv (void)
 {
 #ifdef HAVE_CLEARENV
 	clearenv ();
 #else
-	extern char **environ;
 	environ[0] = NULL;
 #endif
 }
