--- sddm-theme/KeyboardButton.qml.orig	2026-07-07 12:50:32 UTC
+++ sddm-theme/KeyboardButton.qml
@@ -36,17 +36,9 @@ PlasmaComponents.ToolButton {
         Kirigami.Theme.colorSet: Kirigami.Theme.Window
         Kirigami.Theme.inherit: false
 
-        onAboutToShow: {
-            if (instantiator.model === null) {
-                let layouts = keyboard.layouts;
-                layouts.sort((a, b) => a.longName.localeCompare(b.longName));
-                instantiator.model = layouts;
-            }
-        }
-
         Instantiator {
             id: instantiator
-            model: null
+            model: keyboard.layouts
             onObjectAdded: (index, object) => menu.insertItem(index, object)
             onObjectRemoved: (index, object) => menu.removeItem(object)
             delegate: PlasmaComponents.MenuItem {
