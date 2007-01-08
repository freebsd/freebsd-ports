--- src/common/intl.cpp.orig	Wed Mar 22 05:42:10 2006
+++ src/common/intl.cpp	Tue Jan  9 00:27:17 2007
@@ -1452,6 +1452,8 @@
   m_initialized = false;
 }
 
+#define wxSTRINGIZE2(x)	wxSTRINGIZE(x)
+
 // NB: this function has (desired) side effect of changing current locale
 bool wxLocale::Init(const wxChar *szName,
                     const wxChar *szShort,
@@ -1520,7 +1522,7 @@
   bool bOk = true;
   if ( bLoadDefault )
   {
-    bOk = AddCatalog(wxT("wxstd"));
+    bOk = AddCatalog(wxT("wxstd" wxSTRINGIZE2(wxMAJOR_VERSION) wxSTRINGIZE2(wxMINOR_VERSION)));
 
     // there may be a catalog with toolkit specific overrides, it is not
     // an error if this does not exist
