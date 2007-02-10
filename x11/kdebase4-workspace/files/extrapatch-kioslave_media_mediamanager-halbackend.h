--- kioslave/media/mediamanager/halbackend.h.orig	Sun Jan 28 23:58:13 2007
+++ kioslave/media/mediamanager/halbackend.h	Thu Feb  1 02:51:48 2007
@@ -34,6 +34,9 @@
 #include <qobject.h>
 #include <qstringlist.h>
 #include <qstring.h>
+#ifdef Q_OS_FREEBSD
+#include <qtimer.h>
+#endif
 
 #include <config.h>
 
@@ -154,6 +157,9 @@
 
 private slots:
 	void slotResult(KIO::Job *job);
+#ifdef Q_OS_FREEBSD
+	void pollMediaList();
+#endif
 
 /* Hal call-backs -- from gvm*/
 public:
@@ -217,6 +223,10 @@
 	DBusConnection *dbus_connection;
 
 	QMap<KIO::Job *, QString> mount_jobs;
+#ifdef Q_OS_FREEBSD
+	QTimer m_pollTimer;
+	QPtrList<Medium> m_pollMediaList;
+#endif
 };
 
 #endif /* _HALBACKEND_H_ */
