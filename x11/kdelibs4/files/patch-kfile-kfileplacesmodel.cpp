--- ../kfile/kfileplacesmodel.cpp	2008/08/15 10:29:57	847375
+++ ../kfile/kfileplacesmodel.cpp	2008/08/15 10:30:45	847376
@@ -54,7 +54,7 @@
 public:
     Private(KFilePlacesModel *self) : q(self), bookmarkManager(0), sharedBookmarks(0) {}
     ~Private()
-    { 
+    {
         delete sharedBookmarks;
         qDeleteAll(items);
     }
@@ -68,7 +68,7 @@
     Solid::Predicate predicate;
     KBookmarkManager *bookmarkManager;
     KFilePlacesSharedBookmarks * sharedBookmarks;
-    
+
     void reloadAndSignal();
     QList<KFilePlacesItem *> loadBookmarkList();
 
@@ -663,8 +663,7 @@
 {
     Solid::Device device = deviceForIndex(index);
 
-    if ( (device.is<Solid::StorageAccess>() && device.as<Solid::StorageAccess>()->isAccessible())
-     || device.is<Solid::OpticalDisc>()) {
+    if (device.is<Solid::StorageAccess>() && device.as<Solid::StorageAccess>()->isAccessible()) {
 
         Solid::StorageDrive *drive = device.as<Solid::StorageDrive>();
 
@@ -680,17 +679,39 @@
             removable = drive->isRemovable();
         }
 
+        QString iconName;
         QString text;
         QString label = data(index, Qt::DisplayRole).toString().replace('&',"&&");
 
         if (device.is<Solid::OpticalDisc>()) {
-            text = i18n("&Eject '%1'", label);
+            text = i18n("&Release '%1'", label);
         } else if (removable || hotpluggable) {
             text = i18n("&Safely Remove '%1'", label);
+            iconName = "media-eject";
         } else {
             text = i18n("&Unmount '%1'", label);
+            iconName = "media-eject";
         }
 
+        if (!iconName.isEmpty()) {
+            return new QAction(KIcon(iconName), text, 0);
+        } else {
+            return new QAction(text, 0);
+        }
+    }
+
+    return 0;
+}
+
+QAction *KFilePlacesModel::ejectActionForIndex(const QModelIndex &index) const
+{
+    Solid::Device device = deviceForIndex(index);
+
+    if (device.is<Solid::OpticalDisc>()) {
+
+        QString label = data(index, Qt::DisplayRole).toString().replace('&',"&&");
+        QString text = i18n("&Eject '%1'", label);
+
         return new QAction(KIcon("media-eject"), text, 0);
     }
 
@@ -701,6 +722,18 @@
 {
     Solid::Device device = deviceForIndex(index);
 
+    Solid::StorageAccess *access = device.as<Solid::StorageAccess>();
+
+    connect(access, SIGNAL(teardownDone(Solid::ErrorType, QVariant, const QString &)),
+            this, SLOT(_k_storageTeardownDone(Solid::ErrorType, QVariant)));
+
+    device.as<Solid::StorageAccess>()->teardown();
+}
+
+void KFilePlacesModel::requestEject(const QModelIndex &index)
+{
+    Solid::Device device = deviceForIndex(index);
+
     Solid::OpticalDrive *drive = device.parent().as<Solid::OpticalDrive>();
 
     if (drive!=0) {
@@ -709,12 +742,9 @@
 
         drive->eject();
     } else {
-        Solid::StorageAccess *access = device.as<Solid::StorageAccess>();
-
-        connect(access, SIGNAL(teardownDone(Solid::ErrorType, QVariant, const QString &)),
-                this, SLOT(_k_storageTeardownDone(Solid::ErrorType, QVariant)));
-
-        device.as<Solid::StorageAccess>()->teardown();
+        QString label = data(index, Qt::DisplayRole).toString().replace('&',"&&");
+        QString message = i18n("The device '%1' is not a disc and can't be ejected.", label);
+        emit errorMessage(message);
     }
 }
 
