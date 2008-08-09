--- ../kio/kio/kdirwatch.cpp.orig	2008-06-29 18:29:43.000000000 +0200
+++ ../kio/kio/kdirwatch.cpp	2008-06-30 00:40:46.000000000 +0200
@@ -124,7 +124,11 @@
   m_nfsPollInterval = config.readEntry("NFSPollInterval", 5000);
   m_PollInterval = config.readEntry("PollInterval", 500);
 
+#ifdef Q_OS_FREEBSD
+  QString method = config.readEntry("PreferredMethod", "Stat");
+#else
   QString method = config.readEntry("PreferredMethod", "inotify");
+#endif
   if (method == "Fam")
   {
     m_preferredMethod = Fam;
@@ -154,7 +158,7 @@
 
 #ifdef HAVE_FAM
   // It's possible that FAM server can't be started
-  if (FAMOpen(&fc) ==0) {
+  if (m_preferredMethod == Fam && FAMOpen(&fc) ==0) {
     availableMethods << "FAM";
     use_fam=true;
     sn = new QSocketNotifier( FAMCONNECTION_GETFD(&fc),
