--- cinnamon-session/csm-logout-dialog.c.orig	2013-11-24 01:31:17.034682877 +0000
+++ cinnamon-session/csm-logout-dialog.c	2013-11-24 01:32:08.618784768 +0000
@@ -308,11 +308,20 @@
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
