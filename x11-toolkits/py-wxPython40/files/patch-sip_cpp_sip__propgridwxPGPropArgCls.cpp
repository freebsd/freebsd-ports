LLVM/CLANG cannot compile with reinterpret_cast.

https://svnweb.freebsd.org/ports/head/x11-toolkits/py-wxPython30/files/patch-src_gtk_propgrid__wrap.cpp?revision=383979&view=markup
https://github.com/wxWidgets/Phoenix/issues/1416#issuecomment-557263381
https://github.com/wxWidgets/Phoenix/pull/1445

--- sip/cpp/sip_propgridwxPGPropArgCls.cpp.orig	2019-05-22 02:14:14 UTC
+++ sip/cpp/sip_propgridwxPGPropArgCls.cpp
@@ -317,7 +317,7 @@ static int convertTo_wxPGPropArgCls(PyObject *sipPy,vo
             return sipGetState(sipTransferObj);
         }
         else if (sipPy == Py_None) {
-            *sipCppPtr = new wxPGPropArgCls(reinterpret_cast< wxPGProperty * >(NULL));
+            *sipCppPtr = new wxPGPropArgCls(static_cast< wxPGProperty * >(NULL));
             return sipGetState(sipTransferObj);
         }
         else {
