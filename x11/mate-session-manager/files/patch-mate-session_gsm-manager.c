--- mate-session/gsm-manager.c.orig	2014-04-06 23:05:32.991656631 +0000
+++ mate-session/gsm-manager.c	2014-04-06 23:08:50.720647766 +0000
@@ -1101,14 +1101,22 @@
         GError   *error;
         gboolean  ret;
 
+#ifdef HAVE_OLD_UPOWER
         can_hibernate = up_client_get_can_hibernate (manager->priv->up_client);
+#else
+	can_hibernate = FALSE;
+#endif
         if (can_hibernate) {
 
                 /* lock the screen before we suspend */
                 manager_perhaps_lock (manager);
 
                 error = NULL;
+#ifdef HAVE_OLD_UPOWER
                 ret = up_client_hibernate_sync (manager->priv->up_client, NULL, &error);
+#else
+		ret = FALSE;
+#endif
                 if (!ret) {
                         g_warning ("Unexpected hibernate failure: %s",
                                    error->message);
@@ -1124,14 +1132,22 @@
         GError   *error;
         gboolean  ret;
 
+#ifdef HAVE_OLD_UPOWER
         can_suspend = up_client_get_can_suspend (manager->priv->up_client);
+#else
+	can_suspend = FALSE;
+#endif
         if (can_suspend) {
 
                 /* lock the screen before we suspend */
                 manager_perhaps_lock (manager);
 
                 error = NULL;
+#ifdef HAVE_OLD_UPOWER
                 ret = up_client_suspend_sync (manager->priv->up_client, NULL, &error);
+#else
+		ret = FALSE;
+#endif
                 if (!ret) {
                         g_warning ("Unexpected suspend failure: %s",
                                    error->message);
