--- lib/libxview/textsw/es.h.orig	Thu Oct  5 19:15:38 2006
+++ lib/libxview/textsw/es.h	Thu Oct  5 19:15:44 2006
@@ -182,8 +182,8 @@
 } Es_buf_object;
 typedef Es_buf_object *Es_buf_handle;
 
-EXTERN_FUNCTION( caddr_t es_file_get, (Es_handle esh, Es_attribute attribute, DOTDOTDOT ));
-EXTERN_FUNCTION( caddr_t es_mem_get, (Es_handle esh, Es_attribute attribute, DOTDOTDOT ));
+EXTERN_FUNCTION( static caddr_t es_file_get, (Es_handle esh, Es_attribute attribute, DOTDOTDOT ));
+EXTERN_FUNCTION( static caddr_t es_mem_get, (Es_handle esh, Es_attribute attribute, DOTDOTDOT ));
 
 #define ES_READ_BUF_LEN 2047
 #define ES_WRITE_BUF_LEN 2047
