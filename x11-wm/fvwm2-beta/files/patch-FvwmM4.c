--- modules/FvwmM4/FvwmM4.c.orig	Fri Feb  2 16:04:52 2001
+++ modules/FvwmM4/FvwmM4.c	Fri Feb  2 16:05:02 2001
@@ -69,7 +69,7 @@
 int  m4_prefix;                 /* Do GNU m4 prefixing (-P) */
 char m4_options[BUFSIZ];        /* Command line options to m4 */
 char m4_outfile[BUFSIZ] = "";   /* The output filename for m4 */
-char *m4_prog = "m4";           /* Name of the m4 program */
+char *m4_prog = "gm4";           /* Name of the m4 program */
 int  m4_default_quotes;         /* Use default m4 quotes */
 char *m4_startquote = "`";         /* Left quote characters for m4 */
 char *m4_endquote = "'";           /* Right quote characters for m4 */
