--- src/panel/manager.vala.orig	2025-03-22 02:20:18 UTC
+++ src/panel/manager.vala
@@ -23,7 +23,6 @@ namespace Budgie {
 	/**
 	* Available slots
 	*/
-	[Compact]
 	class Screen : GLib.Object {
 		public PanelPosition slots;
 		public Gdk.Rectangle area;
