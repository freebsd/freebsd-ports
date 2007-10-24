--- src/main.c.orig	2007-03-17 15:46:59.000000000 -0400
+++ src/main.c	2007-06-11 15:04:58.000000000 -0400
@@ -3342,7 +3342,6 @@ action_menu_map (WnckWindow *win,
 	return;
     case WNCK_WINDOW_NORMAL:
     case WNCK_WINDOW_DIALOG:
-    case WNCK_WINDOW_MODAL_DIALOG:
     case WNCK_WINDOW_TOOLBAR:
     case WNCK_WINDOW_MENU:
     case WNCK_WINDOW_UTILITY:
