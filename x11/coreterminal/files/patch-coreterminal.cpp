--- coreterminal.cpp.orig	2022-06-05 22:56:33 UTC
+++ coreterminal.cpp
@@ -55,7 +55,7 @@ CoreTerminal::CoreTerminal(settings *s, QWidget *paren
 	: QMainWindow(parent)
 	, uiMode(0)
 	, mRows(30)
-	, mCols(120)
+	, mCols(80)
 	, smi(s)
 {
 	createGUI();
@@ -86,7 +86,7 @@ void CoreTerminal::loadSettings()
 {
 	uiMode = smi->getValue("CoreApps", "UIMode");
 	mRows = smi->getValue("CoreTerminal", "Rows", 30);
-	mCols = smi->getValue("CoreTerminal", "Columns", 120);
+	mCols = smi->getValue("CoreTerminal", "Columns", 80);
 
 	QFont terminalFont = smi->getValue("CoreTerminal", "Font");
 
