--- parse.c.orig	2009-10-10 20:22:13.000000000 +0200
+++ parse.c	2009-10-10 20:22:13.000000000 +0200
@@ -646,6 +646,7 @@
     { "f.deltastop",		FKEYWORD, F_DELTASTOP },
     { "f.destroy",		FKEYWORD, F_DESTROY },
     { "f.downiconmgr",		FKEYWORD, F_DOWNICONMGR },
+    { "f.dumpstate",		FKEYWORD, F_DUMPSTATE },
     { "f.exec",			FSKEYWORD, F_EXEC },
     { "f.file",			FSKEYWORD, F_FILE },
     { "f.focus",		FKEYWORD, F_FOCUS },
@@ -1609,6 +1610,8 @@
     }
 }
 
+static char *m4_defs();
+
 static FILE *start_m4(fraw)
 FILE *fraw;
 {
@@ -1627,7 +1630,6 @@
 	if (fres == 0) {
 		extern Display *dpy;
 		extern char *display_name;
-		static char *m4_defs();
 		char *tmp_file;
 
 		/* Child */
