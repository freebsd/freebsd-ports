--- mate-session/gsm-logout-dialog.c.orig	2014-03-05 20:39:13.000000000 +0000
+++ mate-session/gsm-logout-dialog.c	2014-04-20 18:19:12.537577789 +0000
@@ -214,8 +214,10 @@
 #if defined(HAVE_SYSTEMD) && defined(HAVE_UPOWER)
         else
 #endif
-#ifdef HAVE_UPOWER
+#ifdef HAVE_OLD_UPOWER
         ret = up_client_get_can_suspend (logout_dialog->priv->up_client);
+#else
+        ret = FALSE;
 #endif
         return ret;
 }
@@ -232,8 +234,10 @@
 #if defined(HAVE_SYSTEMD) && defined(HAVE_UPOWER)
         else
 #endif
-#ifdef HAVE_UPOWER
+#ifdef HAVE_OLD_UPOWER
         ret = up_client_get_can_hibernate (logout_dialog->priv->up_client);
+#else
+        ret = FALSE;
 #endif
         return ret;
 }
