--- ./nepomuk/services/storage/resourcemerger.cpp
+++ ./nepomuk/services/storage/resourcemerger.cpp
@@ -499,7 +499,7 @@ Soprano::Node Nepomuk::ResourceMerger::resolveUnmappedNode(const Soprano::Node&
     QUrl newUri = createResourceUri();
     m_mappings.insert( QUrl(node.toN3()), newUri );
 
-    Soprano::Node dateTime( Soprano::LiteralValue( QDateTime::currentDateTime() ) );
+    Soprano::Node dateTime( ( Soprano::LiteralValue( QDateTime::currentDateTime() ) ) );
     m_model->addStatement( newUri, NAO::created(), dateTime, m_graph );
     m_model->addStatement( newUri, NAO::lastModified(), dateTime, m_graph );
