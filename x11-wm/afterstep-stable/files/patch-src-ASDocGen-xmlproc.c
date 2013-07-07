--- src/ASDocGen/xmlproc.c.orig	2008-09-15 15:54:38.000000000 +0000
+++ src/ASDocGen/xmlproc.c	2008-09-15 16:00:20.000000000 +0000
@@ -504,9 +504,10 @@
 	 	char *target = NULL, *target2 ;
 		char *term = NULL, *term2 ;
 		char *ptr = &(state->dest_file[strlen(state->dest_file)-4]);
+		size_t curr_url_anchor_len = state->curr_url_anchor ? strlen(state->curr_url_anchor) : 0;
 		if( state->doc_type == DocType_PHP && *ptr == '.')
 			*ptr = '\0' ;
-		target = safemalloc( strlen( state->dest_file)+5+1+strlen(state->curr_url_anchor)+1);
+		target = safemalloc( strlen( state->dest_file)+5+1+curr_url_anchor_len+1);
 		sprintf( target, "%s#%s", state->dest_file, state->curr_url_anchor );
 		if( state->doc_type == DocType_PHP && *ptr == '\0' )
 			*ptr = '.' ;
