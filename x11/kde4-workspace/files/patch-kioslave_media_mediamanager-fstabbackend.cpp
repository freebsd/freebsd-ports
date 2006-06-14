--- kioslave/media/mediamanager/fstabbackend.cpp	2006/03/23 09:19:38	521680
+++ kioslave/media/mediamanager/fstabbackend.cpp	2006/06/14 09:11:46	551306
@@ -144,7 +144,7 @@
 
 void FstabBackend::handleMtabChange(bool allowNotification)
 {
-	QStringList new_mtabIds, new_mtabEntries;
+	QStringList new_mtabIds;
 	KMountPoint::List mtab = KMountPoint::currentMountPoints();
 
 	KMountPoint::List::iterator it = mtab.begin();
@@ -162,18 +162,19 @@
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
@@ -211,6 +212,10 @@
 			QString mp = medium->mountPoint();
 			QString fs = medium->fsType();
 
+
+			QString mtabEntry = dev + "*" + mp + "*" + fs;
+			m_mtabEntries.remove(mtabEntry);
+
 			QString mime, icon, label;
 			guess(dev, mp, fs, false, mime, icon, label);
 
@@ -226,7 +231,6 @@
 	}
 
 	m_mtabIds = new_mtabIds;
-        m_mtabEntries = new_mtabEntries;
 }
 
 void FstabBackend::handleFstabChange(bool allowNotification)
