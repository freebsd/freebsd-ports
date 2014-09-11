--- mate-session/gsm-manager.c.orig	2014-03-05 20:39:13.000000000 +0000
+++ mate-session/gsm-manager.c	2014-04-20 18:31:08.980429286 +0000
@@ -1166,22 +1166,28 @@
 #if defined(HAVE_SYSTEMD) && defined(HAVE_UPOWER)
         else {
 #endif
-#ifdef HAVE_UPOWER
+#ifdef HAVE_OLD_UPOWER
         can_hibernate = up_client_get_can_hibernate (manager->priv->up_client);
+#else
+        can_hibernate = FALSE;
+#endif
         if (can_hibernate) {
 
                 /* lock the screen before we suspend */
                 manager_perhaps_lock (manager);
 
                 error = NULL;
+#ifdef HAVE_OLD_UPOWER
                 ret = up_client_hibernate_sync (manager->priv->up_client, NULL, &error);
+#else
+                ret = FALSE;
+#endif
                 if (!ret) {
                         g_warning ("Unexpected hibernate failure: %s",
                                    error->message);
                         g_error_free (error);
                 }
         }
-#endif
 #if defined(HAVE_SYSTEMD) && defined(HAVE_UPOWER)
         }
 #endif
@@ -1211,22 +1217,28 @@
 #if defined(HAVE_SYSTEMD) && defined(HAVE_UPOWER)
         else {
 #endif
-#ifdef HAVE_UPOWER
+#ifdef HAVE_OLD_UPOWER
         can_suspend = up_client_get_can_suspend (manager->priv->up_client);
+#else
+        can_suspend = FALSE;
+#endif
         if (can_suspend) {
 
                 /* lock the screen before we suspend */
                 manager_perhaps_lock (manager);
 
                 error = NULL;
+#ifdef HAVE_OLD_UPOWER
                 ret = up_client_suspend_sync (manager->priv->up_client, NULL, &error);
+#else
+                ret = FALSE;
+#endif
                 if (!ret) {
                         g_warning ("Unexpected suspend failure: %s",
                                    error->message);
                         g_error_free (error);
                 }
         }
-#endif
 #if defined(HAVE_SYSTEMD) && defined(HAVE_UPOWER)
         }
 #endif
