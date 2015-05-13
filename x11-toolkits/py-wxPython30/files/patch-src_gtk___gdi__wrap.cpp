--- src/gtk/_gdi_wrap.cpp.orig	2015-04-12 18:02:36 UTC
+++ src/gtk/_gdi_wrap.cpp
@@ -3856,7 +3856,7 @@ const wxString& wxPyLocale::GetSingularS
                                               const wxString& domain) const
 {
     bool found;
-    wxString str( _T("error in translation")); 
+    static wxString str( _T("error in translation")); 
     wxPyBlock_t blocked = wxPyBeginBlockThreads();
     if ((found=wxPyCBH_findCallback(m_myInst, "GetSingularString"))) {
         PyObject* param1 = wx2PyString(origString);
@@ -3878,7 +3878,7 @@ const wxString& wxPyLocale::GetPluralStr
                                             const wxString& domain) const
 {
     bool found;
-    wxString str( _T("error in translation"));
+    static wxString str( _T("error in translation"));
     wxPyBlock_t blocked = wxPyBeginBlockThreads();
     if ((found=wxPyCBH_findCallback(m_myInst, "GetPluralString"))) {
         PyObject* param1 = wx2PyString(origString);
