--- shell/plugins/menu/Menu.qml.orig	2026-10-02 07:08:52 UTC
+++ shell/plugins/menu/Menu.qml
@@ -51,6 +51,10 @@ Item {
   property string userMenuPath: Quickshell.env("HOME") + "/.config/omarchy/extensions/omarchy-menu.jsonc"
   property var defaultMenuItems: []
   property var userMenuItems: []
+  // Entries other packages add to the menu (FreeBSD port addition): merged
+  // after the defaults and before the user's own extension.
+  property string vendorMenuPath: "%%DATADIR%%/vendor/omarchy-menu.jsonc"
+  property var vendorMenuItems: []
   property bool opened: false
   property string mode: "menu"
   readonly property bool dmenuActive: mode === "select" || mode === "input"
@@ -244,7 +248,7 @@ Item {
   // on a per-key basis (so the user can tweak label/icon/action without
   // re-declaring the whole row).
   function rebuildItemsFromSources() {
-    var mergedMenu = MenuModel.mergeMenuSources(root.defaultMenuItems, root.userMenuItems)
+    var mergedMenu = MenuModel.mergeMenuSources(root.defaultMenuItems.concat(root.vendorMenuItems), root.userMenuItems)
     root.providerRevision += 1
     root.providersLoaded = ({})
     root.providerQueue = []
@@ -925,6 +929,16 @@ Item {
     watchChanges: true
     printErrors: false
     onLoaded: { root.defaultMenuItems = root.parseMenuJsonc(text()); root.rebuildItemsFromSources() }
+    onFileChanged: reload()
+  }
+
+  FileView {
+    id: vendorMenuFile
+    path: root.vendorMenuPath
+    watchChanges: true
+    printErrors: false
+    onLoaded: { root.vendorMenuItems = root.parseMenuJsonc(text()); root.rebuildItemsFromSources() }
+    onLoadFailed: { root.vendorMenuItems = []; root.rebuildItemsFromSources() }
     onFileChanged: reload()
   }
 
