--- cinnamon-session/csm-logout-dialog.c.orig	2013-11-22 10:57:50.000000000 +0000
+++ cinnamon-session/csm-logout-dialog.c	2014-04-03 10:33:35.297012436 +0000
@@ -176,13 +176,21 @@
 static gboolean
 csm_logout_supports_system_suspend (CsmLogoutDialog *logout_dialog)
 {
+#ifdef HAVE_OLD_UPOWER
         return ( csm_system_can_suspend (logout_dialog->priv->system) || up_client_get_can_suspend (logout_dialog->priv->up_client) );
+#else
+        return ( csm_system_can_suspend (logout_dialog->priv->system) || FALSE );
+#endif
 }
 
 static gboolean
 csm_logout_supports_system_hibernate (CsmLogoutDialog *logout_dialog)
 {
+#ifdef HAVE_OLD_UPOWER
         return ( csm_system_can_hibernate (logout_dialog->priv->system) || up_client_get_can_hibernate (logout_dialog->priv->up_client) );
+#else
+        return ( csm_system_can_hibernate (logout_dialog->priv->system) || FALSE );
+#endif	
 }
 
 static gboolean
@@ -308,11 +316,20 @@
 		secondary_text = g_strdup (seconds_warning);
 	}
 
+#ifdef __clang__
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
+#endif
+
         gtk_message_dialog_format_secondary_text (GTK_MESSAGE_DIALOG (logout_dialog),
                                                   secondary_text,
                                                   seconds_to_show,
                                                   NULL);
 
+#ifdef __clang__
+#pragma clang diagnostic pop
+#endif
+
         logout_dialog->priv->timeout--;
 
         g_free (secondary_text);
