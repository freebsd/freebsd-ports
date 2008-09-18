--- kioslave/media/mediamanager/halbackend.h.orig	2008-02-13 12:40:36.000000000 +0300
+++ kioslave/media/mediamanager/halbackend.h	2008-09-13 00:51:26.000000000 +0400
@@ -34,6 +34,9 @@
 #include <qobject.h>
 #include <qstringlist.h>
 #include <qstring.h>
+#ifdef Q_OS_FREEBSD
+#include <qtimer.h>
+#endif
 
 #include <config.h>
 
@@ -146,6 +149,9 @@
 
 private slots:
 	void slotResult(KIO::Job *job);
+#ifdef Q_OS_FREEBSD
+	void pollMediaList();
+#endif
 
 /* Hal call-backs -- from gvm*/
 public:
@@ -223,6 +229,10 @@
 	};
 
 	QMap<KIO::Job *, struct mount_job_data*> mount_jobs;
+#ifdef Q_OS_FREEBSD
+	QTimer m_pollTimer;
+	QPtrList<Medium> m_pollMediaList;
+#endif
 };
 
 #endif /* _HALBACKEND_H_ */
