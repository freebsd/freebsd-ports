--- src/panel/applets/clock/ClockApplet.vala.orig	2023-02-19 16:48:41 UTC
+++ src/panel/applets/clock/ClockApplet.vala
@@ -120,7 +120,9 @@ public class ClockApplet : Budgie.Applet {
 		popover.add(menu);
 
 		var time_button = this.new_plain_button(_("System time and date settings"));
-		time_button.clicked.connect(on_date_activate);
+		// datetime panel is disabled in sysutils/budgie-control-center
+		time_button.set_sensitive(false);
+		//time_button.clicked.connect(on_date_activate);
 
 		menu.pack_start(time_button, false, false, 0);
 
