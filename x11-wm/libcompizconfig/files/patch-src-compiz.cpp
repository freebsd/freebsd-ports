--- src/compiz.cpp.orig	2009-03-04 21:22:22.000000000 -0600
+++ src/compiz.cpp	2009-04-06 01:58:35.000000000 -0500
@@ -957,7 +957,7 @@
 
 
 static int
-pluginNameFilter (const struct dirent *name)
+pluginNameFilter (struct dirent *name)
 {
     int length = strlen (name->d_name);
 
@@ -972,7 +972,7 @@
 }
 
 static int
-pluginXMLFilter (const struct dirent *name)
+pluginXMLFilter (struct dirent *name)
 {
     int length = strlen (name->d_name);
 
