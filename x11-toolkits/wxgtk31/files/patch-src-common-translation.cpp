--- src/common/translation.cpp.orig	2011-02-18 15:12:53.000000000 +0600
+++ src/common/translation.cpp	2011-02-18 15:15:10.000000000 +0600
@@ -1302,7 +1302,7 @@
 
 bool wxTranslations::AddStdCatalog()
 {
-    if ( !AddCatalog(wxS("wxstd")) )
+    if ( !AddCatalog(wxS("wxstd") wxSTRINGIZE(wxMAJOR_VERSION) wxSTRINGIZE(wxMINOR_VERSION)) )
         return false;
 
     // there may be a catalog with toolkit specific overrides, it is not
