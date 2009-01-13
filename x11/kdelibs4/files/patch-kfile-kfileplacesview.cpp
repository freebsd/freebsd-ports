--- ../kfile/kfileplacesview.cpp	2008/08/06 22:07:11	843298
+++ ../kfile/kfileplacesview.cpp	2008/08/15 10:30:45	847376
@@ -551,6 +551,9 @@
     QAction *edit = 0;
     QAction *hide = 0;
     QAction *emptyTrash = 0;
+    QAction* eject = 0;
+    QAction* teardown = 0;
+
     if (index.isValid()) {
         if (!placesModel->isDevice(index)) {
             if (placesModel->url(index) == KUrl("trash:/")) {
@@ -561,6 +564,22 @@
             }
 
             edit = menu.addAction(KIcon("document-properties"), i18n("&Edit '%1'...", label));
+        } else {
+            eject = placesModel->ejectActionForIndex(index);
+            if (eject!=0) {
+                eject->setParent(&menu);
+                menu.addAction(eject);
+            }
+
+            teardown = placesModel->teardownActionForIndex(index);
+            if (teardown!=0) {
+                teardown->setParent(&menu);
+                menu.addAction(teardown);
+            }
+
+            if (teardown!=0 || eject!=0) {
+                menu.addSeparator();
+            }
         }
 
         hide = menu.addAction(i18n("&Hide '%1'", label));
@@ -575,19 +594,11 @@
         showAll->setChecked(d->showAll);
     }
 
-    QAction* remove = 0L;
-    QAction* teardown = 0L;
+    QAction* remove = 0;
     if (index.isValid()) {
         if (!placesModel->isDevice(index)) {
             menu.addSeparator();
             remove = menu.addAction( KIcon("edit-delete"), i18n("&Remove '%1'", label));
-        } else {
-            teardown = placesModel->teardownActionForIndex(index);
-            if (teardown!=0) {
-                teardown->setParent(&menu);
-                menu.addSeparator();
-                menu.addAction(teardown);
-            }
         }
     }
 
@@ -646,6 +657,8 @@
         setShowAll(showAll->isChecked());
     } else if (teardown != 0 && result == teardown) {
         placesModel->requestTeardown(index);
+    } else if (eject != 0 && result == eject) {
+        placesModel->requestEject(index);
     }
 
     index = placesModel->closestItem(d->currentUrl);
