--- konqueror/konq_mainwindow.cc.orig	Wed Jul 20 12:04:01 2005
+++ konqueror/konq_mainwindow.cc	Sat Aug  6 00:20:37 2005
@@ -98,6 +98,7 @@
 #include <kiconloader.h>
 #include <kpopupmenu.h>
 #include <kprocess.h>
+#include <kio/netaccess.h>
 #include <kio/scheduler.h>
 #include <kaccelmanager.h>
 #include <kuser.h>
@@ -428,7 +429,7 @@
         QString fileName = path.mid( lastSlash + 1 );
         QString testPath = path.left( lastSlash + 1 );
         if ( ( fileName.find( '*' ) != -1 || fileName.find( '[' ) != -1 || fileName.find( '?' ) != -1 )
-             && ( !url.isLocalFile() || QFile::exists( testPath ) ) )
+             && ( !url.isLocalFile() || QFile::exists( testPath ) ) && !KIO::NetAccess::exists( url, true ) )
         {
             nameFilter = fileName;
             url.setFileName( QString::null );
