--- settings.cpp.orig	2024-10-29 12:23:05 UTC
+++ settings.cpp
@@ -137,9 +137,9 @@ void settings::setAppDefaultSettings(QSettings &settin
     // Add system font to CoreTerminal
     QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
     if ( not monoFont.family().count() ) {
-        monoFont = QFont("monospace", 9);}
+        monoFont = QFont("monospace", 12);}
     if (monoFont.styleHint() != QFont::Monospace) {
-        monoFont = QFont("monospace", 9);}
+        monoFont = QFont("monospace", 12);}
 
     struct passwd *pwent;
     pwent = getpwuid(getuid());
@@ -182,7 +182,7 @@ void settings::setAppDefaultSettings(QSettings &settin
 
     // Check if "CoreTerminal/Columns" exists
     if (!settings.contains("CoreTerminal/Columns")) {
-        settings.setValue("CoreTerminal/Columns", 120);}
+        settings.setValue("CoreTerminal/Columns", 80);}
 
     cSetting->sync();
 }
