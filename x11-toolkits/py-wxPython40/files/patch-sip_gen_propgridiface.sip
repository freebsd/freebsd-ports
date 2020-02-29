LLVM/CLANG cannot compile with reinterpret_cast.

https://svnweb.freebsd.org/ports/head/x11-toolkits/py-wxPython30/files/patch-src_gtk_propgrid__wrap.cpp?revision=383979&view=markup
https://github.com/wxWidgets/Phoenix/issues/1416#issuecomment-557263381
https://github.com/wxWidgets/Phoenix/pull/1445

--- sip/gen/propgridiface.sip.orig	2019-05-22 02:13:01 UTC
+++ sip/gen/propgridiface.sip
@@ -108,7 +108,7 @@ class wxPGPropArgCls (public)
             return sipGetState(sipTransferObj);
         }
         else if (sipPy == Py_None) {
-            *sipCppPtr = new wxPGPropArgCls(reinterpret_cast< wxPGProperty * >(NULL));
+            *sipCppPtr = new wxPGPropArgCls(static_cast< wxPGProperty * >(NULL));
             return sipGetState(sipTransferObj);
         }
         else {
