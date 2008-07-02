--- ./thinglaunch.c.orig	2008-07-02 14:47:23.000000000 +0200
+++ ./thinglaunch.c	2008-07-02 14:47:30.000000000 +0200
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <libgen.h>
 
 static void createWindow();
 static void setupGC();
