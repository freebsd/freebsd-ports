--- ./lib/libxview/notice/notice_pt.c.orig	Tue Jun 29 07:16:40 1993
+++ ./lib/libxview/notice/notice_pt.c	Sat Apr  1 18:25:25 2000
@@ -58,6 +58,7 @@ static notice_buttons_handle notice_butt
 static void     notice_copy_event();
 static Xv_window	notice_get_focus_win();
 static int	notice_show_focus_win();
+static int	notice_quadrant();
 
 /*
  * --------------------------- STATICS ------------------------------
