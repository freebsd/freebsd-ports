--- kioslave/media/mediamanager/fstabbackend.cpp	Mon May 22 20:12:42 2006
+++ kioslave/media/mediamanager/fstabbackend.cpp	Fri Mar 17 11:17:33 2006
@@ -144,7 +144,7 @@
 
 void FstabBackend::handleMtabChange(bool allowNotification)
 {
-	QStringList new_mtabIds, new_mtabEntries;
+	QStringList new_mtabIds;
 	KMountPoint::List mtab = KMountPoint::currentMountPoints();
 
 	KMountPoint::List::iterator it = mtab.begin();
@@ -158,14 +158,6 @@
 
 		if ( ::inExclusionPattern(*it, m_networkSharesOnly) ) continue;
 
-		/* Did we know this already before ? If yes, then
-		   nothing has changed, do not stat the mount point. Avoids
-		   hang if network shares are stalling */
-		QString mtabEntry = dev + "*" + mp + "*" + fs;
-		bool isOldEntry = m_mtabEntries.contains(mtabEntry);
-		new_mtabEntries+=mtabEntry;
-		if (isOldEntry) continue;
-
 		QString id = generateId(dev, mp);
 		new_mtabIds+=id;
 
@@ -226,7 +218,6 @@
 	}
 
 	m_mtabIds = new_mtabIds;
-        m_mtabEntries = new_mtabEntries;
 }
 
 void FstabBackend::handleFstabChange(bool allowNotification)