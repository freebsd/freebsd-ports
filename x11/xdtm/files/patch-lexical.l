--- lexical.l.orig
+++ lexical.l
@@ -1,3 +1,4 @@
+%option yylineno
 %{ /*-*- Mode: C -*-*/
 /**************************************************************************
  ** File     :       lexical.l                                           **
@@ -171,13 +172,6 @@ static int numkeywords = (sizeof(keywordtable)/sizeof(
 
 int parseerror=0;                   /* Number of parse errors */
 char errormessage[255];             /* used for error messsages */
-
-/*
- * ``yylineno'' not POSIX standard, so have to simulate it when using flex.
- */
-#ifdef FLEX_SCANNER
-int yylineno=0;
-#endif
 
 %}
 %%
