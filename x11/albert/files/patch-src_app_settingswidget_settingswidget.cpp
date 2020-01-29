--- src/app/settingswidget/settingswidget.cpp.orig	2018-12-31 18:07:36 UTC
+++ src/app/settingswidget/settingswidget.cpp
@@ -89,7 +89,7 @@ Core::SettingsWidget::SettingsWidget(ExtensionManager 
     connect(ui.checkBox_telemetry, &QCheckBox::toggled, this, [this](bool checked){ telemetry_->enable(checked); });
 
     // AUTOSTART
-#ifdef Q_OS_LINUX
+#if defined Q_OS_LINUX || defined Q_OS_FREEBSD
     QString desktopfile_path = QStandardPaths::locate(QStandardPaths::ApplicationsLocation,
                                                       "albert.desktop",
                                                       QStandardPaths::LocateFile);
