--- rec_parse.y.orig	2001-12-10 17:01:17 UTC
+++ rec_parse.y
@@ -32,9 +32,8 @@
 #include "dmalloc.h"
 #endif
 
-static int yyerror(char *err);
+static int yyerror(rec_t *rec, char *err);
 
-#define YYPARSE_PARAM rec
 #define YYERROR_VERBOSE
 
 #ifdef REC_PARSE_DEBUG
@@ -47,6 +46,7 @@ static feature_list_t FEATURE_ERROR = { 
 %}
 
 %pure_parser
+%parse-param { rec_t *rec }
 
 %union {
   int    ival;
@@ -141,7 +141,7 @@ mode_decl	: MODE STRING
 		| MODE STRING 
 			{
 			  /* Do this first so the default mode gets set correctly*/
-			  $$ = rec_get_mode((rec_t *) rec, $2);
+			  $<rec_mode>$ = rec_get_mode((rec_t *) rec, $2);
 			}
 		  ':' mode_id_list
 			{
@@ -162,12 +162,14 @@ mode_id_list	: mode_id
 			  $$ = $1;
 			  rec_mode_list_append(&$$, $3);
 			}
+			;
 
 mode_id		: STRING
 			{
 			  $$ = rec_get_mode((rec_t *) rec, $1);
 			  free($1);
 			}
+			;
 
 gesture_list	: gesture
 			{
@@ -342,7 +344,7 @@ option		: OPTION STRING STRING
 			
 %%
 
-static int yyerror(char *err)
+static int yyerror(rec_t *rec, char *err)
 {
     char *loc = rec_lex_location_alloc();
     fprintf(stderr, "%s: %s\n", loc, err);
