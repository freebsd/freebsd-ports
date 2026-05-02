--- xpra/dbus/notifications.py.orig	2026-02-01 15:10:38 UTC
+++ xpra/dbus/notifications.py
@@ -121,7 +121,7 @@ class DBUSNotificationsForwarder(dbus.service.Object):
     def GetServerInformation(self):
         # name, vendor, version, spec-version
         from xpra import __version__
-        v = ["xpra-notification-proxy", "xpra", __version__, "0.9"]
+        v = ["xpra-notification-proxy", "xpra", __version__, "1.2"]
         log("GetServerInformation()=%s", v)
         return v
 
