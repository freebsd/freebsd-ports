--- ../nepomuk/core/resourcefiltermodel.cpp.orig	2009-01-06 23:35:20.000000000 +0000
+++ ../nepomuk/core/resourcefiltermodel.cpp	2009-01-09 10:03:30.000000000 +0000
@@ -42,15 +42,9 @@
 using namespace Soprano;
 
 
-uint Soprano::qHash( const Soprano::Node& node )
-{
-    return qHash( node.toString() );
-}
-
-// @deprecated: just for keeping binary compatibility
 uint qHash( const Soprano::Node& node )
 {
-    return Soprano::qHash( node );
+    return qHash( node.toString() );
 }
 
 class Nepomuk::ResourceFilterModel::Private
