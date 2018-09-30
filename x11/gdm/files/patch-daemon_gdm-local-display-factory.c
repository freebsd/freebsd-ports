$OpenBSD: patch-daemon_gdm-local-display-factory_c,v 1.6 2017/03/03 13:01:26 ajacoutot Exp $

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 1ac67f522f5690c27023d98096ca817f12f7eb88 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:28:01 -0400
Subject: drop consolekit support

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 9be58c9ec9a3a411492a5182ac4b0d51fdc3a323 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:48:52 -0400
Subject: require logind support

--- daemon/gdm-local-display-factory.c.orig	Wed Mar  1 16:58:36 2017
+++ daemon/gdm-local-display-factory.c	Fri Mar  3 12:00:56 2017
@@ -42,6 +42,8 @@
 
 #define GDM_LOCAL_DISPLAY_FACTORY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GDM_TYPE_LOCAL_DISPLAY_FACTORY, GdmLocalDisplayFactoryPrivate))
 
+#define CK_SEAT1_PATH                       "/org/freedesktop/ConsoleKit/Seat1"
+
 #define GDM_DBUS_PATH                       "/org/gnome/DisplayManager"
 #define GDM_LOCAL_DISPLAY_FACTORY_DBUS_PATH GDM_DBUS_PATH "/LocalDisplayFactory"
 #define GDM_MANAGER_DBUS_NAME               "org.gnome.DisplayManager.LocalDisplayFactory"
@@ -57,8 +59,10 @@ struct GdmLocalDisplayFactoryPrivate
         /* FIXME: this needs to be per seat? */
         guint            num_failures;
 
+#ifdef WITH_SYSTEMD
         guint            seat_new_id;
         guint            seat_removed_id;
+#endif
 };
 
 enum {
@@ -206,8 +210,10 @@ gdm_local_display_factory_create_transient_display (Gd
 
         g_debug ("GdmLocalDisplayFactory: Creating transient display");
 
-#ifdef ENABLE_USER_DISPLAY_SERVER
-        display = gdm_local_display_new ();
+#if defined ENABLE_USER_DISPLAY_SERVER && defined WITH_SYSTEMD
+	if (LOGIND_RUNNING() > 0) {
+	        display = gdm_local_display_new ();
+	}
 #else
         if (display == NULL) {
                 guint32 num;
@@ -289,7 +295,7 @@ on_display_status_changed (GdmDisplay             *dis
                         /* reset num failures */
                         factory->priv->num_failures = 0;
 
-                        gdm_local_display_factory_sync_seats (factory);
+			create_display (factory, seat_id, session_type, is_initial);
                 }
                 break;
         case GDM_DISPLAY_FAILED:
@@ -368,7 +374,7 @@ create_display (GdmLocalDisplayFactory *factory,
 
         g_debug ("GdmLocalDisplayFactory: Adding display on seat %s", seat_id);
 
-#ifdef ENABLE_USER_DISPLAY_SERVER
+#if defined ENABLE_USER_DISPLAY_SERVER && defined WITH_SYSTEMD
         if (g_strcmp0 (seat_id, "seat0") == 0) {
                 display = gdm_local_display_new ();
                 if (session_type != NULL) {
@@ -400,6 +406,8 @@ create_display (GdmLocalDisplayFactory *factory,
         return display;
 }
 
+#ifdef WITH_SYSTEMD
+
 static void
 delete_display (GdmLocalDisplayFactory *factory,
                 const char             *seat_id) {
@@ -536,6 +544,7 @@ gdm_local_display_factory_stop_monitor (GdmLocalDispla
                 factory->priv->seat_removed_id = 0;
         }
 }
+#endif
 
 static void
 on_display_added (GdmDisplayStore        *display_store,
@@ -576,6 +585,7 @@ static gboolean
 gdm_local_display_factory_start (GdmDisplayFactory *base_factory)
 {
         GdmLocalDisplayFactory *factory = GDM_LOCAL_DISPLAY_FACTORY (base_factory);
+        GdmDisplay             *display;
         GdmDisplayStore *store;
 
         g_return_val_if_fail (GDM_IS_LOCAL_DISPLAY_FACTORY (factory), FALSE);
@@ -594,8 +604,17 @@ gdm_local_display_factory_start (GdmDisplayFactory *ba
                                  factory,
                                  0);
 
-        gdm_local_display_factory_start_monitor (factory);
-        return gdm_local_display_factory_sync_seats (factory);
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                gdm_local_display_factory_start_monitor (factory);
+                return gdm_local_display_factory_sync_seats (factory);
+        }
+#endif
+
+        /* On ConsoleKit just create Seat1, and that's it. */
+        display = create_display (factory, CK_SEAT1_PATH, NULL, TRUE);
+
+        return display != NULL;
 }
 
 static gboolean
@@ -606,7 +625,9 @@ gdm_local_display_factory_stop (GdmDisplayFactory *bas
 
         g_return_val_if_fail (GDM_IS_LOCAL_DISPLAY_FACTORY (factory), FALSE);
 
+#ifdef WITH_SYSTEMD
         gdm_local_display_factory_stop_monitor (factory);
+#endif
 
         store = gdm_display_factory_get_display_store (GDM_DISPLAY_FACTORY (factory));
 
@@ -762,7 +783,9 @@ gdm_local_display_factory_finalize (GObject *object)
 
         g_hash_table_destroy (factory->priv->used_display_numbers);
 
+#ifdef WITH_SYSTEMD
         gdm_local_display_factory_stop_monitor (factory);
+#endif
 
         G_OBJECT_CLASS (gdm_local_display_factory_parent_class)->finalize (object);
 }
