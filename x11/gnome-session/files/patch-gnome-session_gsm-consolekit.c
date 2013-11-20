--- gnome-session/gsm-consolekit.c.orig	2013-06-27 14:49:15.000000000 +0200
+++ gnome-session/gsm-consolekit.c	2013-06-27 15:09:02.000000000 +0200
@@ -233,6 +233,9 @@
 
         manager->priv = GSM_CONSOLEKIT_GET_PRIVATE (manager);
 
+        /* init upower */
+        manager->priv->up_client = up_client_new ();
+
         error = NULL;
 
         if (!gsm_consolekit_ensure_ck_connection (manager, &error)) {
