--- ./lib/libxview/openwin/ow_view.c.orig	Tue Jun 29 07:16:43 1993
+++ ./lib/libxview/openwin/ow_view.c	Sat Apr  1 18:25:26 2000
@@ -48,6 +48,7 @@ void            openwin_remove_split();
 static          openwin_init_view();
 static          openwin_free_view();
 static          openwin_remove_scrollbars();
+static int	openwin_check_view();
 static          openwin_create_viewwindow();
 static          openwin_test_for_sb();
 static          openwin_link_view();
