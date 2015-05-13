--- src/gtk/propgrid_wrap.cpp.orig	2014-11-27 20:51:32 UTC
+++ src/gtk/propgrid_wrap.cpp
@@ -3639,7 +3639,7 @@ bool PyObject_to_wxPGPropArgCls( PyObjec
     }
     else if ( input == Py_None )
     {
-        *v = new wxPGPropArgCls(reinterpret_cast< wxPGProperty * >(NULL));
+        *v = new wxPGPropArgCls(static_cast<wxPGProperty*>(NULL));
     }
     else
     {
