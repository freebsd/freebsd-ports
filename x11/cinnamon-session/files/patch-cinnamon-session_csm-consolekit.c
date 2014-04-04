--- cinnamon-session/csm-consolekit.c.orig	2013-11-22 10:57:50.000000000 +0000
+++ cinnamon-session/csm-consolekit.c	2014-04-03 10:54:40.480547301 +0000
@@ -816,16 +816,22 @@
 csm_consolekit_can_suspend (CsmSystem *system)
 {
         CsmConsolekit *consolekit = CSM_CONSOLEKIT (system);
-
+#ifdef HAVE_OLD_UPOWER
         return up_client_get_can_suspend (consolekit->priv->up_client);
+#else
+	return FALSE;
+#endif
 }
 
 static gboolean
 csm_consolekit_can_hibernate (CsmSystem *system)
 {
         CsmConsolekit *consolekit = CSM_CONSOLEKIT (system);
-
+#ifdef HAVE_OLD_UPOWER
         return up_client_get_can_hibernate (consolekit->priv->up_client);
+#else
+	return FALSE;
+#endif
 }
 
 static void
@@ -835,7 +841,11 @@
         GError *error = NULL;
         gboolean ret;
 
+#ifdef HAVE_OLD_UPOWER
         ret = up_client_suspend_sync (consolekit->priv->up_client, NULL, &error);
+#else
+	ret = FALSE;
+#endif
         if (!ret) {
                 g_warning ("Unexpected suspend failure: %s", error->message);
                 g_error_free (error);
@@ -849,7 +859,11 @@
         GError *error = NULL;
         gboolean ret;
 
+#ifdef HAVE_OLD_UPOWER
         ret = up_client_hibernate_sync (consolekit->priv->up_client, NULL, &error);
+#else
+	ret = FALSE;
+#endif
         if (!ret) {
                 g_warning ("Unexpected hibernate failure: %s", error->message);
                 g_error_free (error);
