--- kioslave/media/mediamanager/fstabbackend.h	2006/03/23 09:19:38	521680
+++ kioslave/media/mediamanager/fstabbackend.h	2006/06/14 09:11:46	551306
@@ -23,6 +23,7 @@
 
 #include <qobject.h>
 #include <qstringlist.h>
+#include <qmap.h>
 
 #ifdef Q_OS_FREEBSD
 #include <qtimer.h>
@@ -53,7 +54,7 @@
 
 	bool m_networkSharesOnly;
 	QStringList m_mtabIds;
-        QStringList m_mtabEntries;
+        QMap<QString, QString> m_mtabEntries;
 	QStringList m_fstabIds;
 #ifdef Q_OS_FREEBSD
 	QTimer m_mtabTimer;
