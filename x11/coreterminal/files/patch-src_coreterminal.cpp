--- src/coreterminal.cpp.orig	2025-09-13 12:09:34 UTC
+++ src/coreterminal.cpp
@@ -48,7 +48,7 @@ CoreTerminal::CoreTerminal(settings *s, QWidget *paren
     : QMainWindow(parent)
     , uiMode(0)
     , mRows(30)
-    , mCols(120)
+    , mCols(80)
     , smi(s)
 {
     createGUI();
@@ -82,7 +82,7 @@ void CoreTerminal::loadSettings()
     // get app's settings
     windowMaximized = smi->getValue("CoreTerminal", "WindowMaximized");
     mRows = smi->getValue("CoreTerminal", "Rows", 30);
-    mCols = smi->getValue("CoreTerminal", "Columns", 120);
+    mCols = smi->getValue("CoreTerminal", "Columns", 80);
 
     QFont tFont = smi->getValue("CoreTerminal", "Font");
     fm = new QFontMetrics(tFont);
