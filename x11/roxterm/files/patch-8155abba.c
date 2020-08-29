diff --git a/src/multitab.h b/src/multitab.h
index 3fd4f39..5934c0e 100644
--- src/multitab.h
+++ src/multitab.h
@@ -104,7 +104,7 @@ typedef gboolean (*MultiWinDeleteHandler)(GtkWidget *, GdkEvent *,
 typedef gboolean (*MultiTabGetShowCloseButton)(gpointer user_data);
 
 /* Needed externally */
-MultiWinGetDisableMenuShortcuts multi_win_get_disable_menu_shortcuts;
+extern MultiWinGetDisableMenuShortcuts multi_win_get_disable_menu_shortcuts;
 
 /* Whether to open a new tab adjacent to current one */
 typedef gboolean (*MultiTabGetNewTabAdjacent)(gpointer user_data);
