--- lumina-desktop/LPanel.cpp.orig	2021-12-26 02:33:45 UTC
+++ lumina-desktop/LPanel.cpp
@@ -74,7 +74,10 @@ LPanel::LPanel(QSettings *file, QString scr, int num, 
     //panelArea->setWindowOpacity(1.0); //fully opaque for the widget on top (apply stylesheet transparencies)
   }
   QTimer::singleShot(1,this, SLOT(UpdatePanel()) );
-  //connect(screen, SIGNAL(resized(int)), this, SLOT(UpdatePanel()) ); //in case the screen resolution changes
+  // This apparently should not be necessary, but the main panel does not
+  // redraw reliably without it.  Be sure to fully test resizing a
+  // FreeBSD VirtualBox guest before replacing this.
+  connect(screen, SIGNAL(resized(int)), this, SLOT(UpdatePanel()) ); //in case the screen resolution changes
 }
 
 LPanel::~LPanel(){
