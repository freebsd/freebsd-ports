--- src/screencastwidget.c.orig	2025-02-17 11:16:56 UTC
+++ src/screencastwidget.c
@@ -57,7 +57,7 @@ struct _ScreenCastWidget
   ScreenCastPersistMode  persist_mode;
 
   DisplayStateTracker   *display_state_tracker;
-  ulong                  monitors_changed_handler_id;
+  gulong                 monitors_changed_handler_id;
 
   ShellIntrospect       *shell_introspect;
   GListModel            *filter_model;
