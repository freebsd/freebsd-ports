--- ./VkCombo.C.orig	Wed Aug 16 23:49:29 2000
+++ ./VkCombo.C	Wed Aug 16 23:41:04 2000
@@ -36,13 +36,21 @@
 char *
 VkCombo::getValue()
 {
+#ifdef OPEN_MOTIF
+    return XmTextFieldGetString(CB_EditBox(_baseWidget));
+#else
     return XmComboBoxGetString(_baseWidget);
+#endif
 }
 
 void
 VkCombo::setIndex(int index)
 {
+#ifdef OPEN_MOTIF
+    XtVaSetValues(_baseWidget,XmNselectedPosition,index);
+#else
     XmComboBoxSelectPos(_baseWidget, index, False);
+#endif
 }
 
 void
@@ -52,7 +60,11 @@
 
     xmstr = XmStringCreateSimple(value);
 
+#ifdef OPEN_MOTIF
+    XmComboBoxSelectItem(_baseWidget, xmstr);
+#else
     XmComboBoxSelectItem(_baseWidget, xmstr, False);
+#endif
 
     XmStringFree(xmstr);
 }
@@ -60,7 +72,11 @@
 void
 VkCombo::selectIndex(int index)
 {
+#ifdef OPEN_MOTIF
+    XtVaSetValues(_baseWidget,XmNselectedPosition,index);
+#else
     XmComboBoxSelectPos(_baseWidget, index, True);
+#endif
 }
 
 void
@@ -70,7 +86,11 @@
 
     xmstr = XmStringCreateSimple(value);
 
+#ifdef OPEN_MOTIF
+    XmComboBoxSelectItem(_baseWidget, xmstr);
+#else
     XmComboBoxSelectItem(_baseWidget, xmstr, True);
+#endif
 
     XmStringFree(xmstr);
 }
@@ -80,7 +100,11 @@
 {
     XmString xmstr = XmStringCreateSimple(newItem);
 
+#ifdef OPEN_MOTIF
+    XmComboBoxAddItem(_baseWidget, xmstr, 0, False);
+#else
     XmComboBoxAddItem(_baseWidget, xmstr, 0);
+#endif
 
     XmStringFree(xmstr);
 }
