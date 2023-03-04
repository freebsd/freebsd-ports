--- src/panel/applets/status/StatusApplet.vala.orig	2023-01-29 15:27:27 UTC
+++ src/panel/applets/status/StatusApplet.vala
@@ -30,7 +30,6 @@ public class StatusSettings : Gtk.Grid {
 public class StatusApplet : Budgie.Applet {
 	public string uuid { public set; public get; }
 	protected Gtk.Box widget;
-	protected BluetoothIndicator blue;
 	protected SoundIndicator sound;
 	protected PowerIndicator power;
 	protected Gtk.EventBox? wrap;
@@ -84,11 +83,6 @@ public class StatusApplet : Budgie.Applet {
 		/* Hook up the popovers */
 		this.setup_popover(power.ebox, power.popover);
 		this.setup_popover(sound.ebox, sound.popover);
-
-		blue = new BluetoothIndicator();
-		widget.pack_start(blue, false, false, 0);
-		blue.show_all();
-		this.setup_popover(blue.ebox, blue.popover);
 	}
 
 	public override void panel_position_changed(Budgie.PanelPosition position) {
@@ -104,7 +98,6 @@ public class StatusApplet : Budgie.Applet {
 		this.manager = manager;
 		manager.register_popover(power.ebox, power.popover);
 		manager.register_popover(sound.ebox, sound.popover);
-		manager.register_popover(blue.ebox, blue.popover);
 	}
 
 	public override bool supports_settings() {
