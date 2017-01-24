--- lxsession/environement.vala.orig	2016-12-05 20:07:14 UTC
+++ lxsession/environement.vala
@@ -331,7 +331,7 @@ namespace Lxsession
             {
                 if (qt_plugin != "")
                 {
-                    Environment.set_variable("QT_PLUGIN_PATH" , qt_plugin + ":/usr/lib64/kde4/plugins:/usr/lib/kde4/plugins", true);
+                    Environment.set_variable("QT_PLUGIN_PATH" , qt_plugin + ":%%QT4_LIBDIR%%/plugins:%%QT5_LIBDIR%%/plugins", true);
                 }
             }
 
