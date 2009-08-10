--- ./kio/kio/kdirwatch.cpp.orgi	2009-01-27 18:07:49.000000000 +0100
+++ ./kio/kio/kdirwatch.cpp	2009-01-27 18:15:04.000000000 +0100
@@ -89,6 +89,9 @@
   } else if (method == "QFSWatch") {
     return KDirWatchPrivate::QFSWatch;
   } else {
+#ifdef Q_OS_FREEBSD
+    return KDirWatchPrivate::Stat;
+#endif
 #ifdef Q_OS_WIN
     return KDirWatchPrivate::QFSWatch;
 #else
@@ -159,7 +162,7 @@
 
 #ifdef HAVE_FAM
   // It's possible that FAM server can't be started
-  if (FAMOpen(&fc) ==0) {
+  if (m_preferredMethod == Fam && FAMOpen(&fc) ==0) {
     availableMethods << "FAM";
     use_fam=true;
     sn = new QSocketNotifier( FAMCONNECTION_GETFD(&fc),
