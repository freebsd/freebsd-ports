--- ./kdecore/io/kdirwatch_p.h.orig	2010-05-17 00:03:59.000000000 +0400
+++ ./kdecore/io/kdirwatch_p.h	2010-08-11 20:13:53.492105378 +0400
@@ -102,7 +102,7 @@
   QHash<QString,QFileSystemWatcher*> m_paths;
 };
 #else
-typedef KFileSystemWatcher QFileSystemWatcher;
+typedef QFileSystemWatcher KFileSystemWatcher;
 #endif
 #endif
 
