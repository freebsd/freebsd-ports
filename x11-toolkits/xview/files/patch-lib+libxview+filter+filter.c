--- ./lib/libxview/filter/filter.c.orig	Tue Jun 29 07:14:57 1993
+++ ./lib/libxview/filter/filter.c	Sat Apr  1 18:25:23 2000
@@ -39,11 +39,12 @@ static char     sccsid[] = "@(#)filter.c
 
 char           *stream_fgets();
 
-enum CharClass
+static enum CharClass
                 breakProc();
-struct CharAction
+static struct CharAction
                 digits();
-
+static
+		any_shell_meta();
 
 struct filter_rec **
 xv_parse_filter_table(in, filename)
@@ -203,10 +204,10 @@ xv_free_filter_table(table)
 {
     int             i;
     for (i = 0; table[i] != NULL; i++) {
-	cfree((char *) table[i]->call);
+	free((char *) table[i]->call);
 	free((char *) table[i]);
     }
-    cfree((char *) table);
+    free((char *) table);
 }
 
 static struct CharAction
