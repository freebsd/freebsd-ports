--- parse.c.orig	1995-02-03 00:17:00 UTC
+++ parse.c
@@ -646,6 +646,7 @@ static TwmKeyword keytable[] = { 
     { "f.deltastop",		FKEYWORD, F_DELTASTOP },
     { "f.destroy",		FKEYWORD, F_DESTROY },
     { "f.downiconmgr",		FKEYWORD, F_DOWNICONMGR },
+    { "f.dumpstate",		FKEYWORD, F_DUMPSTATE },
     { "f.exec",			FSKEYWORD, F_EXEC },
     { "f.file",			FSKEYWORD, F_FILE },
     { "f.focus",		FKEYWORD, F_FOCUS },
@@ -1609,6 +1610,8 @@ do_squeeze_entry (list, name, type, just
     }
 }
 
+static char *m4_defs();
+
 static FILE *start_m4(fraw)
 FILE *fraw;
 {
@@ -1627,7 +1630,6 @@ FILE *fraw;
 	if (fres == 0) {
 		extern Display *dpy;
 		extern char *display_name;
-		static char *m4_defs();
 		char *tmp_file;
 
 		/* Child */
