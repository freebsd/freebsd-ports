--- lib/libxview/file_chooser/xv_path_util.h.orig	Wed Oct  1 23:53:54 2003
+++ lib/libxview/file_chooser/xv_path_util.h	Wed Oct  1 23:53:54 2003
@@ -41,6 +41,7 @@
 
 
 #define xv_free_ref(str)	{if((str)) {xv_free((str)); (str) = NULL;}}
+#define xv_free_regex_t(str)  {if((str)) {regfree((str)); free  ((str)); (str) = NULL;}}
 
 
 EXTERN_FUNCTION(void  xv_error_sprintf, (Frame frame, int use_footer, char *format, DOTDOTDOT) );
