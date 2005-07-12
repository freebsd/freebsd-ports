--- kioslave/media/kdedmodule/fstabbackend.h
+++ kioslave/media/kdedmodule/fstabbackend.h
@@ -24,6 +24,10 @@
 #include <qobject.h>
 #include <qstringlist.h>
 
+#ifdef Q_OS_FREEBSD
+#include <qtimer.h>
+#endif
+
 class FstabBackend : public QObject, public BackendBase
 {
 Q_OBJECT
@@ -38,17 +42,20 @@
 	                  QString &label);
 private slots:
 	void slotDirty(const QString &path);
-
-private:
 	void handleFstabChange();
 	void handleMtabChange();
 
+private:
 	static QString generateId(const QString &devNode,
 	                          const QString &mountPoint);
-	static QString generateName(const QString &devNode);
+	static QString generateName(const QString &devNode,
+	                            const QString &fsType);
 
 	QStringList m_mtabIds;
 	QStringList m_fstabIds;
+#ifdef Q_OS_FREEBSD
+	QTimer m_mtabTimer;
+#endif
 };
 
 #endif
