--- modules/FvwmM4/FvwmM4.c.orig	Wed Nov 21 17:46:27 2001
+++ modules/FvwmM4/FvwmM4.c	Wed Nov 21 17:47:06 2001
@@ -71,7 +71,7 @@
 int  m4_prefix_defines;		/* Add "m4_" to the names of the defines */
 char m4_options[BUFSIZ];        /* Command line options to m4 */
 char m4_outfile[BUFSIZ] = "";   /* The output filename for m4 */
-char *m4_prog = "m4";           /* Name of the m4 program */
+char *m4_prog = "%%LOCALBASE%%/bin/gm4";           /* Name of the m4 program */
 int  m4_default_quotes;         /* Use default m4 quotes */
 char *m4_startquote = "`";         /* Left quote characters for m4 */
 char *m4_endquote = "'";           /* Right quote characters for m4 */
