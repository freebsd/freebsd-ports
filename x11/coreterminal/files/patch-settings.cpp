--- settings.cpp.orig	2021-08-19 22:10:26 UTC
+++ settings.cpp
@@ -92,11 +92,11 @@ void settings::setDefaultSettings()
 	QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
 
 	if (not monoFont.family().count()) {
-		monoFont = QFont("monospace", 9);
+		monoFont = QFont("monospace", 12);
 	}
 
 	if (monoFont.styleHint() != QFont::Monospace) {
-		monoFont = QFont("monospace", 9);
+		monoFont = QFont("monospace", 12);
 	}
 
 	cSetting->setValue("CoreTerminal/Font", monoFont);
