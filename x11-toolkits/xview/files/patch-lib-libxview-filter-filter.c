--- lib/libxview/filter/filter.c.orig	2012-02-03 13:34:17.201860917 -0800
+++ lib/libxview/filter/filter.c	2012-02-03 13:37:57.245727053 -0800
@@ -209,7 +209,7 @@
     free((char *) table);
 }
 
-static struct CharAction
+struct CharAction
 digits(c)
     char            c;
 {
@@ -226,7 +226,7 @@
 }
 
 
-static enum CharClass
+enum CharClass
 breakProc(c)
     char            c;
 {
@@ -246,7 +246,6 @@
 /*
  * Are there any shell meta-characters in string s?
  */
-static
 any_shell_meta_filter(s)
     register char  *s;
 {
