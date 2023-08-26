--- tools/libinput-record.c.orig	2023-03-25 17:59:47 UTC
+++ tools/libinput-record.c
@@ -2577,7 +2577,7 @@ enum fposition {
 
 enum fposition {
 	ERROR,
-	NOFILE,
+	NO_FILE,
 	FIRST,
 	LAST,
 };
@@ -2633,7 +2633,7 @@ find_output_file(int argc, char *argv[], const char **
 		return ERROR;
 	}
 #undef _m
-	return NOFILE;
+	return NO_FILE;
 }
 
 enum options {
