--- plasma/applets/system-monitor/hdd.cpp.orig	2009-07-21 17:19:25.000000000 +0200
+++ plasma/applets/system-monitor/hdd.cpp	2009-08-23 16:07:02.000000000 +0200
@@ -265,8 +265,8 @@
                             data->value("File System Type").toString() <<
                             data->value("Size").toString();
         */
-        if ((data->value("Usage").toString() != "File System" &&
-             data->value("Usage").toString() != "Raid") ||
+        if ((data->value("Usage").toString() != i18n("File System") &&
+             data->value("Usage").toString() != i18n("Raid")) ||
             data->value("File System Type").toString() == "swap") {
             QStringList list = items();
             list.removeAll(uuid);
