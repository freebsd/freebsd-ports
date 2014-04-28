--- mate-session/gsm-logout-dialog.c.orig	2014-04-06 23:10:11.756637268 +0000
+++ mate-session/gsm-logout-dialog.c	2014-04-06 23:11:06.531633477 +0000
@@ -200,13 +200,21 @@
 static gboolean
 gsm_logout_supports_system_suspend (GsmLogoutDialog *logout_dialog)
 {
+#ifdef HAVE_OLD_UPOWER
         return up_client_get_can_suspend (logout_dialog->priv->up_client);
+#else
+	return FALSE;
+#endif
 }
 
 static gboolean
 gsm_logout_supports_system_hibernate (GsmLogoutDialog *logout_dialog)
 {
+#ifdef HAVE_OLD_UPOWER
         return up_client_get_can_hibernate (logout_dialog->priv->up_client);
+#else
+	return FALSE;
+#endif
 }
 
 static gboolean
