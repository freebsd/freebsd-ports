--- contrib/include/wx/fl/frmview.h.orig	Wed Nov  5 00:02:21 2003
+++ contrib/include/wx/fl/frmview.h	Wed Nov  5 00:03:08 2003
@@ -114,7 +114,7 @@
 
     // if file name is empty, views are are not saved/loaded
 
-    virtual void Init( wxWindow* pMainFrame, const wxString& settingsFile = "" );
+    virtual void Init( wxWindow* pMainFrame, const wxString& settingsFile = wxEmptyString );
 
     // synonyms
     wxFrame* GetParentFrame();
