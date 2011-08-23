--- src/notification/notification.c.orig	2011-08-15 19:54:26.000000000 +0200
+++ src/notification/notification.c	2011-08-15 19:54:44.000000000 +0200
@@ -103,7 +103,7 @@ notifyLogMessage (const char   *componen
 
     n = notify_notification_new (logLevel,
                                  message,
-                                 iconUri, NULL);
+                                 iconUri);
 
     notify_notification_set_timeout (n, nd->timeout);
 
