--- scripts/sawfish-menu.jl.orig	Tue May 20 11:49:42 2003
+++ scripts/sawfish-menu.jl	Tue May 20 11:50:54 2003
@@ -106,7 +106,8 @@
     (g-signal-connect menu "deactivate" gtk-main-quit)
     (setq menu-selected nil)
     (gtk-menu-popup-interp menu nil nil 0 (or timestamp 0) position)
-    (gtk-main)
+    (when (memq 'visible (GTK-WIDGET-FLAGS menu))
+      (gtk-main))
     menu-selected))
 
 
