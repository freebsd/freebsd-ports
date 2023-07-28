--- mainwindow.cpp
+++ mainwindow.cpp
@@ -859,6 +859,9 @@ QStringList getDriveList()
 #if QT_VERSION >= QT_VERSION_CHECK(5,4,0)
 #if defined(Q_OS_LINUX)
     #define VFAT "vfat"
+#elif defined(Q_OS_FREEBSD)
+    #define VFAT "msdosfs"
+    Q_UNUSED(crostini_detected)
 #elif defined(Q_OS_WIN)
     #define VFAT "FAT32"
     Q_UNUSED(crostini_detected)
