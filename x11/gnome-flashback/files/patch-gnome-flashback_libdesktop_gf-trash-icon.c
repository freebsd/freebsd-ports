--- gnome-flashback/libdesktop/gf-trash-icon.c.orig	2021-11-02 10:13:49 UTC
+++ gnome-flashback/libdesktop/gf-trash-icon.c
@@ -179,10 +179,10 @@ gf_trash_icon_create_file_monitor (GfIcon *icon)
   g_clear_object (&self->monitor);
 
   error = NULL;
-  self->monitor = g_file_monitor_directory (gf_icon_get_file (GF_ICON (self)),
-                                            G_FILE_MONITOR_WATCH_MOVES,
-                                            self->cancellable,
-                                            &error);
+  self->monitor = g_file_monitor (gf_icon_get_file (GF_ICON (self)),
+                                  G_FILE_MONITOR_NONE,
+                                  self->cancellable,
+                                  &error);
 
   if (error != NULL)
     {
