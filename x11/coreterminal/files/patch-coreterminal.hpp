--- coreterminal.hpp.orig	2021-08-18 11:17:12 UTC
+++ coreterminal.hpp
@@ -53,6 +53,7 @@ public :
 private:
     int             uiMode;
 	settings        *smi;
+	QFont           terminalFont;
 
 	void loadSettings();
 	void createGUI();
