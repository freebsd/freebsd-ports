--- src/widgets/qlistview.cpp.orig	Sat Nov  5 05:43:59 2005
+++ src/widgets/qlistview.cpp	Sat Nov  5 05:45:00 2005
@@ -3231,6 +3231,7 @@
     d->focusItem = 0;
     d->selectAnchor = 0;
     d->pressedItem = 0;
+    d->highlighted = 0;
 
     // if it's down its downness makes no sense, so undown it
     d->buttonDown = FALSE;
