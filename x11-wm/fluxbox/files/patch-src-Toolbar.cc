diff -u -r src/Toolbar.cc.orig src/Toolbar.cc
--- src/Toolbar.cc.orig	Sat Dec  7 22:41:57 2002
+++ src/Toolbar.cc	Tue Oct 28 01:03:30 2003
@@ -204,6 +204,7 @@
 }
 		
 void Toolbar::reconfigure() {
+	I18n *i18n = I18n::instance();
 	int head_x = 0,
 			head_y = 0,
 			head_w,
@@ -318,6 +319,7 @@
 		frame.clock_w = 0;
 #else // !HAVE_STRFTIME
 	
+	using namespace FBNLS;
 	frame.clock_w =	screen()->getToolbarStyle()->font.textWidth(
 		i18n->getMessage(
 			ToolbarSet, ToolbarNoStrftimeLength,
@@ -521,6 +523,7 @@
 void Toolbar::checkClock(bool redraw, bool date) {
 	time_t tmp = 0;
 	struct tm *tt = 0;
+	I18n *i18n = I18n::instance();
 
 	if ((tmp = time(NULL)) != -1) {
 		if (! (tt = localtime(&tmp))) {
@@ -545,9 +549,11 @@
 			return;
 #else // !HAVE_STRFTIME
 		char t[9];
+		using namespace FBNLS;
+
 		if (date) {
 			// format the date... with special consideration for y2k ;)
-			if (screen()->getDateFormat() == Blackbox::B_EuropeanDate) {
+			if (screen()->getDateFormat() == Fluxbox::B_EuropeanDate) {
 				sprintf(t,
 					i18n->getMessage(
 				 		ToolbarSet, ToolbarNoStrftimeDateFormatEu,
@@ -1101,6 +1107,8 @@
 		CommonSet, CommonAutoHide,
 		"Auto hide"),
 		2);
+
+	using namespace FBNLS;
 	insert(i18n->getMessage(
 		ToolbarSet, ToolbarEditWkspcName,
 		"Edit current workspace name"),
