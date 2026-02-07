--- src/tabbar.c.orig	2024-03-13 19:45:34 UTC
+++ src/tabbar.c
@@ -1314,7 +1314,7 @@ rxvt_append_page( rxvt_t* r, int profile,
 		if( p.we_wordc > 1)
 		    rxvt_msg( DBG_ERROR, DBG_TABBAR,
 			    "Too many words when expanding %s\n", cwdOption );
-		else
+		else if( NOT_NULL( *p.we_wordv ) )
 		{
 		    filename = *p.we_wordv;
 
