--- src/window.c	31 Jul 2004 21:26:05 -0000	1.333
+++ src/window.c	4 Aug 2004 15:55:42 -0000
@@ -1619,6 +1619,11 @@ window_takes_focus_on_map (MetaWindow *w
     case META_WINDOW_NORMAL:
     case META_WINDOW_DIALOG:
     case META_WINDOW_MODAL_DIALOG:
+      /* Don't do focus stealing stuff; lame cop-out while we work on
+       * fixing http://bugzilla.gnome.org/show_bug.cgi?id=149028
+       */
+      return TRUE;
+
       if (window->focus_despite_user_time)
 	return TRUE;
