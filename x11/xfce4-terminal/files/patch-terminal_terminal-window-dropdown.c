--- terminal/terminal-window-dropdown.c.orig	2026-03-08 11:12:45 UTC
+++ terminal/terminal-window-dropdown.c
@@ -567,11 +567,13 @@ terminal_window_dropdown_finalize (GObject *object)
   if (dropdown->animation_timeout_id != 0)
     g_source_remove (dropdown->animation_timeout_id);
 
+#ifdef HAVE_GTK_LAYER_SHELL
   if (dropdown->set_monitor_idle_id != 0)
     g_source_remove (dropdown->set_monitor_idle_id);
 
   if (dropdown->monitor_removed_idle_id != 0)
     g_source_remove (dropdown->monitor_removed_idle_id);
+#endif
 
   if (dropdown->status_icon != NULL)
     g_object_unref (G_OBJECT (dropdown->status_icon));
