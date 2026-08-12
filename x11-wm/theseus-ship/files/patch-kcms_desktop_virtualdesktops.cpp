--- kcms/desktop/virtualdesktops.cpp.orig	2024-10-09 20:27:02 UTC
+++ kcms/desktop/virtualdesktops.cpp
@@ -18,6 +18,7 @@
 #include <KPluginFactory>
 #include <QDBusConnection>
 #include <QDBusMessage>
+#include <QQmlEngine>
 
 K_PLUGIN_FACTORY_WITH_JSON(VirtualDesktopsFactory,
                            "kcm_kwin_virtualdesktops.json",
