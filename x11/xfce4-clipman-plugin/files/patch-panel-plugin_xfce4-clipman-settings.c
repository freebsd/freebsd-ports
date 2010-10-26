--- panel-plugin/xfce4-clipman-settings.c.orig	2009-09-12 02:59:31.000000000 +0200
+++ panel-plugin/xfce4-clipman-settings.c	2010-10-26 16:39:52.000000000 +0200
@@ -661,7 +661,7 @@
       if (unique_app_send_message (app, UNIQUE_ACTIVATE, NULL) == UNIQUE_RESPONSE_OK)
         {
           g_object_unref (app);
-          return;
+          return 0;
         }
     }
   g_signal_connect (app, "message-received", G_CALLBACK (cb_unique_app), NULL);
