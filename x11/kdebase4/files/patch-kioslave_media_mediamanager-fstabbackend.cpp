--- kioslave/media/mediamanager/fstabbackend.cpp.orig	Mon May 22 20:12:42 2006
+++ kioslave/media/mediamanager/fstabbackend.cpp	Fri Jun 16 08:56:20 2006
@@ -111,6 +111,7 @@
 	if ( mount->mountType() == "swap"
 	  || mount->mountType() == "tmpfs"
 	  || mount->mountType() == "sysfs"
+	  || mount->mountType() == "fdescfs"
 	  || mount->mountType() == "kernfs"
 	  || mount->mountType() == "usbfs"
 	  || mount->mountType().contains( "proc" )
@@ -144,7 +145,7 @@
 
 void FstabBackend::handleMtabChange(bool allowNotification)
 {
-	QStringList new_mtabIds, new_mtabEntries;
+	QStringList new_mtabIds;
 	KMountPoint::List mtab = KMountPoint::currentMountPoints();
 
 	KMountPoint::List::iterator it = mtab.begin();
@@ -162,18 +163,19 @@
 		   nothing has changed, do not stat the mount point. Avoids
 		   hang if network shares are stalling */
 		QString mtabEntry = dev + "*" + mp + "*" + fs;
-		bool isOldEntry = m_mtabEntries.contains(mtabEntry);
-		new_mtabEntries+=mtabEntry;
-		if (isOldEntry) continue;
+		if(m_mtabEntries.contains(mtabEntry)) {
+		        new_mtabIds += m_mtabEntries[mtabEntry];
+			continue;
+		}
 
 		QString id = generateId(dev, mp);
 		new_mtabIds+=id;
+		m_mtabEntries[mtabEntry] = id;
 
 		if ( !m_mtabIds.contains(id) && m_fstabIds.contains(id) )
 		{
 			QString mime, icon, label;
 			guess(dev, mp, fs, true, mime, icon, label);
-
 			m_mediaList.changeMediumState(id, true, false,
 			                              mime, icon, label);
 		}
@@ -211,6 +213,10 @@
 			QString mp = medium->mountPoint();
 			QString fs = medium->fsType();
 
+
+			QString mtabEntry = dev + "*" + mp + "*" + fs;
+			m_mtabEntries.remove(mtabEntry);
+
 			QString mime, icon, label;
 			guess(dev, mp, fs, false, mime, icon, label);
 
@@ -226,7 +232,6 @@
 	}
 
 	m_mtabIds = new_mtabIds;
-        m_mtabEntries = new_mtabEntries;
 }
 
 void FstabBackend::handleFstabChange(bool allowNotification)
