--- ./src/config/Run.cc.orig	2011-05-20 18:25:35.000000000 +0200
+++ ./src/config/Run.cc	2011-07-06 17:21:57.000000000 +0200
@@ -28,7 +28,7 @@
     int pid = -1;
     FILE * process;
 
-    process = popen("pidof "PACKAGE_NAME, "r");
+    process = popen("pgrep "PACKAGE_NAME, "r");
 
     if (process)
     {
