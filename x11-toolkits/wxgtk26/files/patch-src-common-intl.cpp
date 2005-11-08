===================================================================
RCS file: /pack/cvsroots/wxwidgets/wxWidgets/src/common/intl.cpp,v
retrieving revision 1.166
retrieving revision 1.166.2.1
diff -u -r1.166 -r1.166.2.1
--- src/common/intl.cpp	2005/09/18 23:38:06	1.166
+++ src/common/intl.cpp	2005/09/28 09:48:03	1.166.2.1
@@ -1260,9 +1260,14 @@
             inputConv =
             csConv = new wxCSConv(m_charset);
     }
-    else // no conversion needed
+    else // no need to convert the encoding
     {
+        // we still need the conversion for Unicode build
+#if wxUSE_UNICODE
+        inputConv = wxConvCurrent;
+#else // !wxUSE_UNICODE
         inputConv = NULL;
+#endif
     }
 
     // conversion to apply to msgid strings before looking them up: we only
