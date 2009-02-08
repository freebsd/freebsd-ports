--- ../kded/kded.cpp	(revision 918837)
+++ ../kded/kded.cpp	(revision 918838)
@@ -115,9 +115,8 @@
    KToolInvocation::kdeinitExecWait( "kdontchangethehostname", args );
 }
 
-Kded::Kded(bool checkUpdates)
-  : b_checkUpdates(checkUpdates),
-    m_needDelayedCheck(false)
+Kded::Kded()
+  : m_needDelayedCheck(false)
 {
   _self = this;
 
@@ -280,7 +279,7 @@
     KSharedConfig::Ptr config = KGlobal::config();
     // Ensure the service exists.
     KService::Ptr service = KService::serviceByDesktopPath("kded/"+obj+".desktop");
-    if (!service) 
+    if (!service)
         return;
     KConfigGroup cg(config, QString("Module-%1").arg(service->desktopEntryName()));
     cg.writeEntry("autoload", autoload);
@@ -290,7 +289,7 @@
 bool Kded::isModuleAutoloaded(const QString &obj) const
 {
     KService::Ptr s = KService::serviceByDesktopPath("kded/"+obj+".desktop");
-    if (!s) 
+    if (!s)
         return false;
     return isModuleAutoloaded(s);
 }
@@ -307,7 +306,7 @@
 bool Kded::isModuleLoadedOnDemand(const QString &obj) const
 {
     KService::Ptr s = KService::serviceByDesktopPath("kded/"+obj+".desktop");
-    if (!s) 
+    if (!s)
         return false;
     return isModuleLoadedOnDemand(s);
 }
@@ -446,7 +445,7 @@
 
 void Kded::updateDirWatch()
 {
-  if (!b_checkUpdates) return;
+  if (!bCheckUpdates) return;
 
   delete m_pDirWatch;
   m_pDirWatch = new KDirWatch;
@@ -471,7 +470,7 @@
 {
   delete KSycoca::self();
 
-  if (!b_checkUpdates) return;
+  if (!bCheckUpdates) return;
 
   if (delayedCheck) return;
 
@@ -921,7 +920,7 @@
      checkStamps = cg.readEntry("CheckFileStamps", true);
      delayedCheck = cg.readEntry("DelayedCheck", false);
 
-     Kded *kded = new Kded(false); // Build data base
+     Kded *kded = new Kded(); // Build data base
 
      KDE_signal(SIGTERM, sighandler);
      KDE_signal(SIGHUP, sighandler);
