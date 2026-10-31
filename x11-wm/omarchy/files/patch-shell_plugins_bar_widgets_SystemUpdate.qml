--- shell/plugins/bar/widgets/SystemUpdate.qml.orig
+++ shell/plugins/bar/widgets/SystemUpdate.qml
@@ -59,7 +59,7 @@
     text: "\uf021"
     slotSize: Style.bar.statusSlot
     fontSize: Style.font.caption
-    tooltipText: "Pending Omarchy Updates"
+    tooltipText: "Pending " + (Quickshell.env("OMARCHY_DISTRIBUTION_NAME") || "Omarchy") + " Updates"
     onPressed: root.runUpdate()
   }
 }
