--- WINGs/wapplication.c.orig	2013-05-03 02:55:29.000000000 +0900
+++ WINGs/wapplication.c	2013-05-03 02:56:04.000000000 +0900
@@ -159,7 +159,7 @@
 	if (path)
 		goto out;
 
-	path = checkFile("/usr/local/GNUstep", appdir, ext, resource);
+	path = checkFile(PREFIX "/GNUstep", appdir, ext, resource);
 	if (path)
 		goto out;
 
