--- ./kdecore/io/kdirwatch.cpp.orig	2010-05-17 00:03:59.000000000 +0400
+++ ./kdecore/io/kdirwatch.cpp	2010-08-11 20:13:53.553022509 +0400
@@ -95,7 +95,7 @@
 #ifdef Q_OS_WIN
     return KDirWatchPrivate::QFSWatch;
 #elif defined(Q_OS_FREEBSD)
-    return KDirWatchPrivate::Stat;
+    return KDirWatchPrivate::QFSWatch;
 #else
     return KDirWatchPrivate::INotify;
 #endif
@@ -151,7 +151,11 @@
   m_preferredMethod = methodFromString(method);
 
   // The nfs method defaults to the normal (local) method
+#if defined(Q_OS_FREEBSD)
+  m_nfsPreferredMethod = methodFromString(config.readEntry("nfsPreferredMethod", "Stat"));
+#else
   m_nfsPreferredMethod = methodFromString(config.readEntry("nfsPreferredMethod", method));
+#endif
 
   QStringList availableMethods;
 
@@ -988,7 +992,16 @@
 
 #ifdef HAVE_QFILESYSTEMWATCHER
   if (e->m_mode == QFSWatchMode) {
-    fsWatcher->removePath(e->path);
+    if ( e->m_status == Normal ) {
+      fsWatcher->removePath(e->path);
+      kDebug(7001).nospace() << "Cancelled QFSWatch for " << e->path;
+    }
+    else {
+      if (e->isDir)
+        removeEntry(0, QDir::cleanPath(e->path+"/.."), e);
+      else
+        removeEntry(0, QFileInfo(e->path).absolutePath(), e);
+    }
   }
 #endif
   if (e->m_mode == StatMode) {
@@ -1664,8 +1677,7 @@
   EntryMap::Iterator it;
   it = m_mapEntries.find(path);
   if(it != m_mapEntries.end()) {
-    Entry entry = *it;  // deep copy to not point to uninialized data (can happen inside emitEvent() )
-    Entry *e = &entry;
+    Entry *e = &(*it);
     e->dirty = true;
     int ev = scanEntry(e);
     if (ev != NoChange)
@@ -1676,28 +1688,20 @@
       else
         addEntry(0, QFileInfo(e->path).absolutePath(), e, true);
     } else
+    if(ev == Created) {
+      if(!useQFSWatch(e))
+#ifdef HAVE_SYS_INOTIFY_H
+        if(!useINotify(e))
+#endif
+          useStat(e);
+    } else
     if (ev == Changed && e->isDir && e->m_entries.count()) {
       Entry* sub_entry = 0;
       Q_FOREACH(sub_entry, e->m_entries) {
-        if(e->isDir) { // ####### !?!? Already checked above
-          if (QFileInfo(sub_entry->path).isDir()) // ##### !? no comparison between sub_entry->path and path?
-            break;
-        } else {
-          if (QFileInfo(sub_entry->path).isFile())
-            break;
-        }
+        if (QFileInfo(sub_entry->path).exists())
+          break;
       }
       if (sub_entry) {
-        removeEntry(0, e, sub_entry);
-        //KDE_struct_stat stat_buf;
-        //QByteArray tpath = QFile::encodeName(path);
-        //KDE_stat(tpath, &stat_buf);
-
-        if(!useQFSWatch(sub_entry))
-#ifdef HAVE_SYS_INOTIFY_H
-          if(!useINotify(sub_entry))
-#endif
-            useStat(sub_entry);
         fswEventReceived(sub_entry->path);
       }
     }
