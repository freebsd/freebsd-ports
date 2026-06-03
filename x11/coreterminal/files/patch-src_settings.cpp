--- src/settings.cpp.orig	2024-12-30 17:49:40 UTC
+++ src/settings.cpp
@@ -129,11 +129,11 @@ void settings::setAppDefaultSettings(QSettings& settin
     // Add system font to CoreTerminal
     QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
     if (not monoFont.family().length()) {
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
     }
 
     if (monoFont.styleHint() != QFont::Monospace) {
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
     }
 
     struct passwd* pwent;
@@ -186,7 +186,7 @@ void settings::setAppDefaultSettings(QSettings& settin
 
     // Check if "CoreTerminal/Columns" exists
     if (!settings.contains("CoreTerminal/Columns")) {
-        settings.setValue("CoreTerminal/Columns", 120);
+        settings.setValue("CoreTerminal/Columns", 80);
     }
 
     cSetting->sync();
