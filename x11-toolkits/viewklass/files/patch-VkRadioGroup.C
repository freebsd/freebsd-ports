--- ./VkRadioGroup.C.orig	Wed Jul 23 02:25:08 2003
+++ ./VkRadioGroup.C	Wed Jul 23 02:31:58 2003
@@ -47,11 +47,15 @@
 #include <Xm/ToggleBG.h>
 #include <Xm/PushB.h>
 #include <Xm/PushBG.h>
+#include <iostream>
+
+using std::cerr;
+using std::endl;
 
 VkRadioGroup::VkRadioGroup()
 	: VkWidgetList()
 {
-    _currentlySelected = 0;
+    //_currentlySelected = 0;
 }
 
 void 
@@ -77,9 +81,9 @@
 void 
 VkRadioGroup::remove(Widget item)
 {
-    if (*_currentlySelected == item)
+    /*if (*_currentlySelected == item)
         _currentlySelected = 0;
-    else if (_currentlySelected > VkWidgetList::find(item))
+    else */ if (_currentlySelected > VkWidgetList::find(item))
         _currentlySelected --;
 
 	XtRemoveCallback(item, XmNvalueChangedCallback,
