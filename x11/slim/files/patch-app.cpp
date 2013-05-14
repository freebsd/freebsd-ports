--- ./app.cpp.orig	2012-12-31 07:03:42.000000000 -0600
+++ ./app.cpp	2013-03-23 14:10:35.000000000 -0500
@@ -931,7 +931,7 @@
 	}
 
 	if (!hasVtSet && daemonmode) {
-		server[argc++] = (char*)"vt07";
+		server[argc++] = (char*)"vt09";
 	}
 	server[argc] = NULL;
 
