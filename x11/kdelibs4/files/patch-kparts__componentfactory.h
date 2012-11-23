--- kparts/componentfactory.h.orig	2012-11-23 16:20:14.000000000 +0800
+++ kparts/componentfactory.h	2012-11-23 16:20:22.000000000 +0800
@@ -28,6 +28,8 @@
 #endif
 #include <kmimetypetrader.h>
 
+#include <QtCore/QFile>
+
 namespace KParts
 {
     namespace ComponentFactory
@@ -81,7 +83,7 @@
                                           const QStringList &args = QStringList(),
                                           int *error = 0 )
         {
-            KLibrary *library = KLibLoader::self()->library( QString( libraryName ) ); // compatibility hack
+            KLibrary *library = KLibLoader::self()->library( QFile::decodeName( libraryName ) ); // compatibility hack
             if ( !library )
             {
                 if ( error )
@@ -135,7 +137,7 @@
                 return 0;
             }
 
-            return createPartInstanceFromLibrary<T>( library.toLocal8Bit().data(), parentWidget,
+             return createPartInstanceFromLibrary<T>( QFile::encodeName( library ).constData(), parentWidget,
                                                      parent, args, error );
         }
 #endif
