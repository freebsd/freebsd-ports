--- lib/X11/imLcPrs.c.orig	Wed Dec  4 00:16:59 2002
+++ lib/X11/imLcPrs.c	Wed Dec  4 00:17:44 2002
@@ -518,13 +518,13 @@
     FILE *fp;
     DefTree **ptop;
 {
-    char tb[65535];
+    char tb[8192];
     char* tbp;
     struct stat st;
 
     if (fstat (fileno (fp), &st) != -1) {
 	unsigned long size = (unsigned long) st.st_size;
-	if (size < sizeof tb) tbp = tb;
+	if (size <= sizeof tb) tbp = tb;
 	else tbp = malloc (size);
 
 	if (tbp != NULL) {
