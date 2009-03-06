--- rec_parse.y.orig	2001-12-10 18:01:17.000000000 +0100
+++ rec_parse.y	2009-03-03 00:57:09.000000000 +0100
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
