--- src/server.c.orig	2014-03-03 20:48:49.000000000 +0000
+++ src/server.c	2014-04-08 09:17:40.268173534 +0000
@@ -72,10 +72,10 @@
   const char *home_dir;
   GError *error = NULL;
 
-  if (G_UNLIKELY (getuid () != geteuid () ||
-                  getgid () != getegid () ||
-                  geteuid () == 0 || 
-                  getegid () == 0)) {
+  if (G_UNLIKELY ((getuid () != geteuid () &&
+                  getgid () != getegid ()) &&
+                  geteuid () == 0 &&
+                  getegid () == 0)) {
     g_printerr ("Wrong euid/egid, exiting.\n");
     return EXIT_FAILURE;
   }
