--- docklets/Battery/BatteryDocklet.vala.orig	2026-08-04 01:49:12 UTC
+++ docklets/Battery/BatteryDocklet.vala
@@ -35,7 +35,7 @@ namespace Docky {
     public bool is_supported () { return true; }
 
     public Plank.DockElement make_element (string launcher, GLib.File file) {
-      return new BatteryUPowerDockItem.with_dockitem_file (file);
+      return (Plank.DockElement) new BatteryUPowerDockItem.with_dockitem_file (file);
     }
   }
 }
