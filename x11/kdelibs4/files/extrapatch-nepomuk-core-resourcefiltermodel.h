--- ../nepomuk/core/resourcefiltermodel.h.orig	2009-01-06 23:35:20.000000000 +0000
+++ ../nepomuk/core/resourcefiltermodel.h	2009-01-09 10:15:12.000000000 +0000
@@ -113,9 +113,7 @@
     };
 }
 
-namespace Soprano {
-    uint qHash( const Node& node );
-}
+uint qHash( const Soprano::Node& node );
 
 
 #endif
