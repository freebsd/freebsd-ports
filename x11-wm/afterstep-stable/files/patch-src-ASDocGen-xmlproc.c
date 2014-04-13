$FreeBSD$

--- src/ASDocGen/xmlproc.c.orig	2013-05-01 06:34:11.000000000 -0700
+++ src/ASDocGen/xmlproc.c	2014-04-13 10:29:12.000000000 -0700
@@ -179,7 +179,7 @@
 				fputs( "\\&", state->dest_fp );	
 			else if ( c == '\\' && state->doc_type == DocType_NROFF ) 
 				fputc( '\\', state->dest_fp );	
-			else if ( c == '' && state->doc_type == DocType_NROFF ) 
+			else if ( c == 152 /*''*/ && state->doc_type == DocType_NROFF ) 
 				c = '~';
 			fputc( c, state->dest_fp );
 		}		   
@@ -514,9 +514,10 @@
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
