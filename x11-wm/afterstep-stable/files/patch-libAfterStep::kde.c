$FreeBSD$

--- libAfterStep/kde.c.orig	Thu Jun 22 21:30:40 2006
+++ libAfterStep/kde.c	Thu Jun 22 21:31:14 2006
@@ -115,8 +115,9 @@
 			{
  				if( (tag = make_kde_config_comment_tag()) != NULL )
 				{	
+					size_t len;
 					++i ;
-					int len = strlen( &buffer[i] ) ;
+					len = strlen( &buffer[i] ) ;
 					while( len > 0 && isspace( buffer[i+len-1] ) ) --len ;
 					if( len > 0 ) 
 					{
