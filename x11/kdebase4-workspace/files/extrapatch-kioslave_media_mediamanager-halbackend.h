--- kioslave/media/mediamanager/halbackend.h.orig	Mon Jan 15 12:31:32 2007
+++ kioslave/media/mediamanager/halbackend.h	Wed Feb 21 15:01:12 2007
@@ -34,6 +34,9 @@
 #include <qobject.h>
 #include <qstringlist.h>
 #include <qstring.h>
+#ifdef Q_OS_FREEBSD
+#include <qtimer.h>
+#endif
 
 #include <config.h>
 
@@ -156,6 +159,9 @@
 
 private slots:
 	void slotResult(KIO::Job *job);
+#ifdef Q_OS_FREEBSD
+	void pollMediaList();
+#endif
 
 /* Hal call-backs -- from gvm*/
 public:
@@ -233,6 +239,10 @@
 	};
 
 	QMap<KIO::Job *, struct mount_job_data*> mount_jobs;
+#ifdef Q_OS_FREEBSD
+	QTimer m_pollTimer;
+	QPtrList<Medium> m_pollMediaList;
+#endif
 };
 
 #endif /* _HALBACKEND_H_ */
