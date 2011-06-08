--- examples/tree/lex.yy.c.orig	Tue Apr 15 11:56:25 2003
+++ examples/tree/lex.yy.c	Tue Apr 15 11:57:27 2003
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <unistd.h>
 # define U(x) x
 # define NLSTATE yyprevious=YYNEWLINE
 # define BEGIN yybgin = yysvec + 1 +
@@ -66,7 +67,7 @@
 int yymorfg;
 extern char *yysptr, yysbuf[];
 int yytchar;
-FILE *yyin = {stdin}, *yyout = {stdout};
+FILE *yyin = STDIN_FILENO, *yyout = STDOUT_FILENO;
 extern int yylineno;
 struct yysvf { 
 	struct yywork *yystoff;
