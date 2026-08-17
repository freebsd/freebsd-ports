--- docklets/Battery/BatteryUPowerDockItem.vala.orig	2026-08-04 01:49:12 UTC
+++ docklets/Battery/BatteryUPowerDockItem.vala
@@ -222,11 +222,6 @@ namespace Docky {
           return false;
         }
 
-        var replacement = new BatteryDockItem.with_dockitem_file(backing_file);
-        if (container.replace(replacement, this)) {
-          fallback_pending = false;
-        }
-
         return false;
       });
     }
