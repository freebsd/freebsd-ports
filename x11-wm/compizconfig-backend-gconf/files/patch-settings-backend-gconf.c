--- settings-backend/gconf.c.orig	2007-08-14 05:26:13.000000000 -0400
+++ settings-backend/gconf.c	2007-08-17 21:44:10.000000000 -0400
@@ -28,7 +28,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <dirent.h>
 
@@ -441,7 +441,12 @@
 
 	    if (strcmp (token + len - prefixLen, prefix[i]) == 0)
 	    {
-		char *buffer = strndup (token, len - prefixLen);
+		char *buffer;
+		if ((buffer = (char *) malloc(len - prefixLen + 1)) != NULL) {
+			bzero (buffer, len - prefixLen + 1);
+			strncpy (buffer, token, len - prefixLen);
+		}
+
 		if (buffer)
 		{
 		    setting = ccsFindSetting (plugin, buffer,
