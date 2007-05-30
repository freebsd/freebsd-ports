--- parse.c.orig	Wed May 30 19:28:55 2007
+++ parse.c	Wed May 30 19:29:16 2007
@@ -1609,6 +1609,8 @@
     }
 }
 
+static char *m4_defs();
+
 static FILE *start_m4(fraw)
 FILE *fraw;
 {
@@ -1627,7 +1629,6 @@
 	if (fres == 0) {
 		extern Display *dpy;
 		extern char *display_name;
-		static char *m4_defs();
 		char *tmp_file;
 
 		/* Child */
