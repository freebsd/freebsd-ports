--- ./nepomuk/services/storage/datamanagementmodel.h.orig	2011-09-10 03:15:36.003035686 +0200
+++ ./nepomuk/services/storage/datamanagementmodel.h	2011-09-10 03:17:46.033066393 +0200
@@ -156,7 +156,7 @@
                         const QString& app,
                         Nepomuk::StoreIdentificationMode identificationMode = Nepomuk::IdentifyNew,
                         Nepomuk::StoreResourcesFlags flags = Nepomuk::NoStoreResourcesFlags,
-                        const QHash<QUrl, QVariant>& additionalMetadata = QHash<QUrl, QVariant>() );
+                        const QHash<QUrl, QVariant>& additionalMetadata = (QHash<QUrl, QVariant>()) );
 
     /**
      * Merges two resources into one. Properties from \p resource1
@@ -188,7 +188,7 @@
                          const QString& userSerialization = QString(),
                          Nepomuk::StoreIdentificationMode identificationMode = Nepomuk::IdentifyNew,
                          Nepomuk::StoreResourcesFlags flags = Nepomuk::NoStoreResourcesFlags,
-                         const QHash<QUrl, QVariant>& additionalMetadata = QHash<QUrl, QVariant>());
+                         const QHash<QUrl, QVariant>& additionalMetadata = (QHash<QUrl, QVariant>()));
 
     /**
      * Describe a set of resources, i.e. retrieve all their properties.
@@ -200,7 +200,7 @@
     //@}
 
 private:
-    QUrl createGraph(const QString& app = QString(), const QHash<QUrl, QVariant>& additionalMetadata = QHash<QUrl, QVariant>());
+    QUrl createGraph(const QString& app = QString(), const QHash<QUrl, QVariant>& additionalMetadata = (QHash<QUrl, QVariant>()));
     QUrl createGraph(const QString& app, const QMultiHash<QUrl, Soprano::Node>& additionalMetadata);
 
     /**
