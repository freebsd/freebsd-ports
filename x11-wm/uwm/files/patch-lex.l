$FreeBSD$

--- lex.l.orig	Sun Oct 23 13:20:00 1988
+++ lex.l	Wed Sep 25 14:50:06 2002
@@ -81,7 +81,6 @@
 char *s;
 {
     char *ptr;
-    char *malloc();
 
     ptr = malloc(strlen(s) + 1);
     if (ptr == NULL) {
