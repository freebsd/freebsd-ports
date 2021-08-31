--- coreterminal.cpp.orig	2021-08-18 11:17:12 UTC
+++ coreterminal.cpp
@@ -27,6 +27,7 @@
     *
 */
 
+#include <iostream>
 #include <QWidget>
 #include <QCloseEvent>
 #include <QHBoxLayout>
@@ -34,6 +35,8 @@
 #include <QDir>
 #include <QFileInfo>
 #include <QMessageBox>
+#include <QTabBar>
+#include <QStyle>
 
 #include <cprime/appopenfunc.h>
 #include <cprime/variables.h>
@@ -75,6 +78,7 @@ CoreTerminal::~CoreTerminal()
 void CoreTerminal::loadSettings()
 {
 	uiMode = smi->getValue("CoreApps", "UIMode");
+	terminalFont = smi->getValue("CoreTerminal", "Font");
 }
 
 void CoreTerminal::createGUI()
@@ -239,7 +243,40 @@ void CoreTerminal::setWindowProperties()
 //        setStyleSheet( "#base { background-color: palette(Window); }" );
 //    }
 
-    resize( 800, 500 );
+    QFontMetrics fm( terminalFont );
+    std::cerr	<< "fm.boundingRect(\"M\").width() = " << fm.boundingRect( "M" ).width() 
+		<< "\nfm.boundingRect(\"M\").height() = " << fm.boundingRect("M").height() 
+		<< "\nfm.averageCharWidth() = " << fm.averageCharWidth()
+		<< "\nfm.height() = " << fm.height()
+		<< "\nfm.lineSpacing() = " << fm.lineSpacing()
+		<< "\nfm.leading() = " << fm.leading()
+		<< "\ntabBar.width() = " << TabWidget->tabBar()->width()
+		<< "\ntabBar.height() = " << TabWidget->tabBar()->height()
+		<< "\nframeGeometry.height() = " << frameGeometry().height()
+		<< "\ngeometry.height() = " << geometry().height()
+		<< "\nPM_ScrollBarExtent = " << qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent) 
+		<< "\nPM_TabBarTabOverlap = " << qApp->style()->pixelMetric(QStyle::PM_TabBarTabOverlap)
+		<< "\nPM_TabBarTabVSpace = " << qApp->style()->pixelMetric(QStyle::PM_TabBarTabVSpace)
+		<< "\nPM_TabBarBaseHeight = " << qApp->style()->pixelMetric(QStyle::PM_TabBarBaseHeight)
+		<< "\nPM_TabBarBaseOverlap = " << qApp->style()->pixelMetric(QStyle::PM_TabBarBaseOverlap)
+		<< "\ntabBar()->height() = " << TabWidget->tabBar()->height()
+		<< "\ntabBar()->tabRect().height() = " << TabWidget->tabBar()->tabRect(0).height()
+		<< '\n';
+
+    int width = fm.averageCharWidth() * 80
+		+ qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent)
+		+ 2;
+    /*
+     * Perfect size =
+     * tabBar->height() +7 for Fusion, +4 for QtCurve, +3 for Windows
+     * tabBar->tabRect(0).height() seems to align:
+     * 36 for Fusion, 33 for QtCurve, 32 for Windows using 12pt font
+     * Also verified with several other styles and font sizes
+     */
+    int height = fm.height() * 30
+		+ TabWidget->tabBar()->tabRect(0).height()
+		+ 1;
+    resize(width, height);
 
     if (uiMode != 0) {
         setWindowFlags( windowFlags() );
