--- cinnamon-session/csm-logout-dialog.c.orig	2014-04-12 10:25:22.000000000 +0000
+++ cinnamon-session/csm-logout-dialog.c	2014-04-24 08:07:46.179191996 +0000
@@ -188,6 +188,8 @@
         return csm_system_can_suspend (logout_dialog->priv->system);
 #elif defined(HAVE_OLD_UPOWER)
         return up_client_get_can_suspend (logout_dialog->priv->up_client);
+#else
+	return FALSE;	
 #endif
 }
 
@@ -198,6 +200,8 @@
         return csm_system_can_hibernate (logout_dialog->priv->system);
 #elif defined(HAVE_OLD_UPOWER)
         return up_client_get_can_hibernate (logout_dialog->priv->up_client);
+#else
+	return FALSE;	
 #endif
 }
 
