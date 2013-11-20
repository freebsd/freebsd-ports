--- js/gdm/loginDialog.js.orig	2012-03-24 21:19:24.000000000 -0500
+++ js/gdm/loginDialog.js	2012-03-24 21:21:23.000000000 -0500
@@ -301,11 +301,17 @@
         this.actor.connect('key-focus-in', Lang.bind(this, this._moveFocusToItems));
     },
 
-    _moveFocusToItems: function() {
-        let hasItems = Object.keys(this._items).length > 0;
+    _hasItems: function() {
+        for (let userName in this._items) {
+            return true;
+        }
+        return false;
+    },
 
-        if (!hasItems)
+    _moveFocusToItems: function() {
+        if (!this._hasItems()) {
             return;
+        }
 
         if (global.stage.get_key_focus() != this.actor)
             return;
