--- tools/designer/designer/mainwindow.cpp	2000/11/18 17:50:58	1.1
+++ tools/designer/designer/mainwindow.cpp	2000/11/18 17:53:21
@@ -125,7 +125,7 @@
     : QMainWindow( 0, "mainwindow", WType_TopLevel | WDestructiveClose ),
 #endif
       grd( 10, 10 ), sGrid( TRUE ), snGrid( TRUE ), restoreConfig( TRUE ), splashScreen( TRUE ),
-      docPath( "$QTDIR/doc/html" ), client( asClient )
+      docPath( QT_PREFIX "/share/doc/qt2/html" ), client( asClient )
 {
     self = this;
     setIcon( PixmapChooser::loadPixmap( "logo" ) );
@@ -3144,7 +3144,7 @@
 	QMessageBox::information( this, tr( "Create Template" ), tr( "Couldn't create the template" ) );
 	return;
     }
-    fn.prepend( QString( getenv( "QTDIR" ) ) + "/tools/designer/templates/" );
+    fn.prepend( QT_PREFIX "/share/qt2/designer/templates/" );
     fn.append( ".ui" );
     QFile f( fn );
     if ( !f.open( IO_WriteOnly ) ) {
@@ -3236,9 +3236,9 @@
 
 void MainWindow::openHelpForDialog( const QString &dia )
 {
-    QString manualdir = QString( getenv( "QTDIR" ) ) + "/tools/designer/manual/book1.html";
+    QString manualdir = QT_PREFIX "/share/qt2/designer/manual/book1.html";
     if ( !QFile::exists( manualdir ) )
-	manualdir = QString( getenv( "QTDIR" ) ) + "/doc/html/designer/book1.html";
+	manualdir = QT_PREFIX "/share/doc/qt2/html/designer/book1.html";
     QFile file( manualdir );
     if ( !file.open( IO_ReadOnly ) )
 	return;
