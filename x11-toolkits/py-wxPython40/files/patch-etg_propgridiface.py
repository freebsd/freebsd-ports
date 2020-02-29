LLVM/CLANG cannot compile with reinterpret_cast.

https://svnweb.freebsd.org/ports/head/x11-toolkits/py-wxPython30/files/patch-src_gtk_propgrid__wrap.cpp?revision=383979&view=markup
https://github.com/wxWidgets/Phoenix/issues/1416#issuecomment-557263381
https://github.com/wxWidgets/Phoenix/pull/1445

--- etg/propgridiface.py.orig	2019-05-21 23:12:12 UTC
+++ etg/propgridiface.py
@@ -89,7 +89,7 @@ def run():
             return sipGetState(sipTransferObj);
         }
         else if (sipPy == Py_None) {
-            *sipCppPtr = new wxPGPropArgCls(reinterpret_cast< wxPGProperty * >(NULL));
+            *sipCppPtr = new wxPGPropArgCls(static_cast< wxPGProperty * >(NULL));
             return sipGetState(sipTransferObj);
         }
         else {
