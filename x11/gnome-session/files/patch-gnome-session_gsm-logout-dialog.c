--- gnome-session/gsm-logout-dialog.c.orig	2009-08-25 04:03:42.000000000 -0400
+++ gnome-session/gsm-logout-dialog.c	2009-08-26 14:27:18.000000000 -0400
@@ -27,9 +27,8 @@
 #include <glib/gi18n.h>
 #include <gtk/gtk.h>
 
-#include <devkit-power-gobject/devicekit-power.h>
-
 #include "gsm-logout-dialog.h"
+#include "gsm-power-manager.h"
 #include "gsm-consolekit.h"
 #include "gdm.h"
 
@@ -50,7 +49,7 @@ struct _GsmLogoutDialogPrivate
 {
         GsmDialogLogoutType  type;
 
-        DkpClient           *dkp_client;
+        GsmPowerManager     *power_manager;
         GsmConsolekit       *consolekit;
 
         int                  timeout;
@@ -142,7 +141,7 @@ gsm_logout_dialog_init (GsmLogoutDialog 
         gtk_window_set_keep_above (GTK_WINDOW (logout_dialog), TRUE);
         gtk_window_stick (GTK_WINDOW (logout_dialog));
 
-        logout_dialog->priv->dkp_client = dkp_client_new ();
+        logout_dialog->priv->power_manager = gsm_get_power_manager ();
 
         logout_dialog->priv->consolekit = gsm_get_consolekit ();
 
@@ -166,9 +165,9 @@ gsm_logout_dialog_destroy (GsmLogoutDial
                 logout_dialog->priv->timeout_id = 0;
         }
 
-        if (logout_dialog->priv->dkp_client) {
-                g_object_unref (logout_dialog->priv->dkp_client);
-                logout_dialog->priv->dkp_client = NULL;
+        if (logout_dialog->priv->power_manager) {
+                g_object_unref (logout_dialog->priv->power_manager);
+                logout_dialog->priv->power_manager = NULL;
         }
 
         if (logout_dialog->priv->consolekit) {
@@ -183,9 +182,7 @@ static gboolean
 gsm_logout_supports_system_suspend (GsmLogoutDialog *logout_dialog)
 {
         gboolean ret;
-        g_object_get (logout_dialog->priv->dkp_client,
-                      "can-suspend", &ret,
-                      NULL);
+        ret = gsm_power_manager_can_suspend (logout_dialog->priv->power_manager);
         return ret;
 }
 
@@ -193,9 +190,7 @@ static gboolean
 gsm_logout_supports_system_hibernate (GsmLogoutDialog *logout_dialog)
 {
         gboolean ret;
-        g_object_get (logout_dialog->priv->dkp_client,
-                      "can-hibernate", &ret,
-                      NULL);
+        ret = gsm_power_manager_can_hibernate (logout_dialog->priv->power_manager);
         return ret;
 }
 
