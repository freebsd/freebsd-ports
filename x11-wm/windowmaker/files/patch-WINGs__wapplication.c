--- WINGs/wapplication.c.orig	2015-08-11 18:41:14 UTC
+++ WINGs/wapplication.c
@@ -187,7 +187,7 @@ char *WMPathForResourceOfType(const char
 	if (path)
 		goto out;
 
-	path = checkFile("/usr/local/GNUstep", appdir, ext, resource);
+	path = checkFile(PREFIX "/GNUstep", appdir, ext, resource);
 	if (path)
 		goto out;
 
