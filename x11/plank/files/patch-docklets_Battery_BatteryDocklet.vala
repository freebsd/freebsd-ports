--- docklets/Battery/BatteryDocklet.vala.orig	2025-02-28 03:58:18 UTC
+++ docklets/Battery/BatteryDocklet.vala
@@ -35,9 +35,11 @@ namespace Docky {
     public bool is_supported () { return true; }
 
     public Plank.DockElement make_element (string launcher, GLib.File file) {
-      return (BatteryUPowerDockItem.is_supported)
-                ? (Plank.DockElement) new BatteryUPowerDockItem.with_dockitem_file (file)
-                : (Plank.DockElement) new BatteryDockItem.with_dockitem_file (file);
+      if (BatteryUPowerDockItem.is_supported) {
+        return (Plank.DockElement) new BatteryUPowerDockItem.with_dockitem_file (file);
+      }
+
+      return null;
     }
   }
 }
