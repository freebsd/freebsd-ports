--- drivemount/drive-button.c.orig	Tue Aug 23 05:16:27 2005
+++ drivemount/drive-button.c	Tue Aug 23 20:37:43 2005
@@ -24,6 +24,7 @@
 #  include <config.h>
 #endif
 
+#include <string.h>
 #include "drive-button.h"
 #include <glib/gi18n.h>
 #include <gdk/gdkkeysyms.h>
@@ -710,11 +711,13 @@ run_command (DriveButton *self, const ch
 
 	GList *volumes;
 	GnomeVFSVolume *volume;
+	char *uri;
+	char *mount_path;
 
 	volumes = gnome_vfs_drive_get_mounted_volumes (self->drive);
 	volume = GNOME_VFS_VOLUME (volumes->data);
-	char *uri = gnome_vfs_volume_get_activation_uri (volume);
-	char *mount_path = gnome_vfs_get_local_path_from_uri (uri);
+	uri = gnome_vfs_volume_get_activation_uri (volume);
+	mount_path = gnome_vfs_get_local_path_from_uri (uri);
 	g_free (uri);
 
 	gnome_vfs_drive_get_display_name (self->drive);
@@ -794,6 +797,11 @@ drive_button_ensure_popup (DriveButton *
     char *display_name, *tmp, *label;
     int action;
     GtkWidget *item;
+    GList *volumes;
+    GnomeVFSVolume *volume = NULL;
+    GnomeVFSDeviceType volume_type;
+    GCallback callback;
+    const char *action_icon = GTK_STOCK_OPEN;
 
     if (self->popup_menu) return;
 
@@ -869,8 +877,7 @@ drive_button_ensure_popup (DriveButton *
     g_free (display_name);
     display_name = tmp;
 
-	GCallback callback = G_CALLBACK (open_drive);
-	const char *action_icon = GTK_STOCK_OPEN;
+	callback = G_CALLBACK (open_drive);
 
 	switch (device_type) {
 	case GNOME_VFS_DEVICE_TYPE_VIDEO_DVD:
