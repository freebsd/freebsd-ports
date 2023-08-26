--- tools/libinput-record.c.orig	2023-08-26 05:37:23.373226000 -0700
+++ tools/libinput-record.c	2023-08-26 05:37:57.514545000 -0700
@@ -2577,7 +2577,7 @@
 
 enum fposition {
 	ERROR,
-	NOFILE,
+	NO_FILE,
 	FIRST,
 	LAST,
 };
@@ -2633,7 +2633,7 @@
 		return ERROR;
 	}
 #undef _m
-	return NOFILE;
+	return NO_FILE;
 }
 
 enum options {
