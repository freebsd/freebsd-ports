--- lib/libxview/notice/notice_set.c.orig	Sun Mar 26 00:02:43 2006
+++ lib/libxview/notice/notice_set.c	Sun Mar 26 00:04:18 2006
@@ -22,7 +22,6 @@
 #include <xview/win_input.h>
 #include <xview/cms.h>
 
-extern char		*strchr();
 Pkg_private Xv_opaque	notice_generic_set();
 #ifdef  OW_I18N
 static CHAR     **notice_string_set();
