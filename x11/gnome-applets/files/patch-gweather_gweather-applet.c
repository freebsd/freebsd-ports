--- gweather/gweather-applet.c.orig	2011-03-07 17:35:07.000000000 +0100
+++ gweather/gweather-applet.c	2011-03-07 17:35:33.000000000 +0100
@@ -471,8 +471,7 @@ update_finish (WeatherInfo *info, gpoint
 			 if (icon == NULL)
 				 icon = "stock-unknown";
 	           	 
-			 n = notify_notification_new (message, detail, icon,
-					 gw_applet->container);
+			 n = notify_notification_new (message, detail, icon);
 	
 		   	 notify_notification_show (n, &error);
 			 if (error)
