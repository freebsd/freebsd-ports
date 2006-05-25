--- lib/libxview/textsw/txt_event.c.orig	2006-01-04 11:15:27.000000000 +0000
+++ lib/libxview/textsw/txt_event.c
@@ -22,7 +22,6 @@ static char     sccsid[] = "@(#)txt_even
 #include <xview_private/win_keymap.h>
 
 
-extern int      errno;
 Pkg_private Notify_error win_post_event();
 Pkg_private void     ev_blink_caret();
 
