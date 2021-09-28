$OpenBSD: patch-src_backends_x11_meta-input-settings-x11_c,v 1.5 2021/06/04 10:56:17 ajacoutot Exp $

Index: src/backends/x11/meta-input-settings-x11.c
--- src/backends/x11/meta-input-settings-x11.c.orig
+++ src/backends/x11/meta-input-settings-x11.c
@@ -45,6 +45,7 @@ typedef struct _MetaInputSettingsX11Private
 #ifdef HAVE_LIBGUDEV
   GUdevClient *udev_client;
 #endif
+  bool dummy_field; // struct needs at least one element to compile
 } MetaInputSettingsX11Private;
 
 G_DEFINE_TYPE_WITH_PRIVATE (MetaInputSettingsX11, meta_input_settings_x11,
@@ -765,11 +766,10 @@ meta_input_settings_x11_set_tablet_aspect_ratio (MetaI
 static void
 meta_input_settings_x11_dispose (GObject *object)
 {
-#ifdef HAVE_LIBGUDEV
   MetaInputSettingsX11 *settings_x11 = META_INPUT_SETTINGS_X11 (object);
   MetaInputSettingsX11Private *priv =
     meta_input_settings_x11_get_instance_private (settings_x11);
-
+#ifdef HAVE_LIBGUDEV
   g_clear_object (&priv->udev_client);
 #endif
 
@@ -938,11 +938,10 @@ meta_input_settings_x11_class_init (MetaInputSettingsX
 static void
 meta_input_settings_x11_init (MetaInputSettingsX11 *settings)
 {
-#ifdef HAVE_LIBGUDEV
   MetaInputSettingsX11Private *priv =
     meta_input_settings_x11_get_instance_private (settings);
   const char *subsystems[] = { NULL };
-
+#ifdef HAVE_LIBGUDEV
   priv->udev_client = g_udev_client_new (subsystems);
 #endif
 }
