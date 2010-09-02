--- kdecore/io/kdirwatch.cpp.orig	2010-06-02 03:38:59.000000000 -0400
+++ kdecore/io/kdirwatch.cpp	2010-06-02 03:42:23.000000000 -0400
@@ -164,7 +164,7 @@
 
 #ifdef HAVE_FAM
   // It's possible that FAM server can't be started
-  if (FAMOpen(&fc) ==0) {
+  if (m_preferredMethod == Fam && FAMOpen(&fc) ==0) {
     availableMethods << "FAM";
     use_fam=true;
     sn = new QSocketNotifier( FAMCONNECTION_GETFD(&fc),
