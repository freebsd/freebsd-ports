--- rec_parse.y.orig	Mon Dec  2 11:54:46 2002
+++ rec_parse.y	Mon Dec  2 11:55:02 2002
@@ -162,12 +162,14 @@
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
