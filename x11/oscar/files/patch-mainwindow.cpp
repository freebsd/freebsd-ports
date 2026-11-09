--- mainwindow.cpp.orig	2026-10-31 09:48:51 UTC
+++ mainwindow.cpp
@@ -1235,6 +1235,9 @@ QStringList getDriveList()
 #if QT_VERSION >= QT_VERSION_CHECK(5,4,0)
 #if defined(Q_OS_LINUX)
     #define VFAT "vfat"
+#elif defined(Q_OS_FREEBSD)
+    #define VFAT "msdosfs"
+    Q_UNUSED(crostini_detected)
 #elif defined(Q_OS_WIN)
     #define VFAT "FAT32"
     Q_UNUSED(crostini_detected)
