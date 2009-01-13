--- ../kfile/kfileplacesmodel.h	2008/08/15 10:29:57	847375
+++ ../kfile/kfileplacesmodel.h	2008/08/15 10:30:45	847376
@@ -60,7 +60,9 @@
     KBookmark bookmarkForIndex(const QModelIndex &index) const;
 
     QAction *teardownActionForIndex(const QModelIndex &index) const;
+    QAction *ejectActionForIndex(const QModelIndex &index) const;
     void requestTeardown(const QModelIndex &index);
+    void requestEject(const QModelIndex &index);
     void requestSetup(const QModelIndex &index);
 
     void addPlace(const QString &text, const KUrl &url, const QString &iconName = QString(), const QString &appName = QString());
