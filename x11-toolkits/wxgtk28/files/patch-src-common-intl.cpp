--- src/common/intl.cpp.orig	Mon Jan  8 21:27:30 2007
+++ src/common/intl.cpp	Mon Jan  8 21:27:18 2007
@@ -1585,7 +1585,7 @@
   bool bOk = true;
   if ( bLoadDefault )
   {
-    bOk = AddCatalog(wxT("wxstd"));
+    bOk = AddCatalog(wxT("wxstd" wxSTRINGIZE(wxMAJOR_VERSION) wxSTRINGIZE(wxMINOR_VERSION)));
 
     // there may be a catalog with toolkit specific overrides, it is not
     // an error if this does not exist
