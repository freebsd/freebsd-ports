--- ./src/actionGroups/windowListGroup.vala.orig	2013-01-23 23:33:16.000000000 +0100
+++ ./src/actionGroups/windowListGroup.vala	2013-01-24 21:41:21.000000000 +0100
@@ -76,13 +76,13 @@
     private void load() {
         unowned GLib.List<Wnck.Window?> windows = this.screen.get_windows();
         
-        var matcher = Bamf.Matcher.get_default();
+        //var matcher = Bamf.Matcher.get_default();
 
         foreach (var window in windows) {
             if (window.get_window_type() == Wnck.WindowType.NORMAL
             	&& !window.is_skip_pager() && !window.is_skip_tasklist()) {
                 var application = window.get_application();
-                var bamf_app = matcher.get_application_for_xid((uint32)window.get_xid());
+                //var bamf_app = matcher.get_application_for_xid((uint32)window.get_xid());
                 
                 string name = window.get_name();
                 
@@ -91,7 +91,8 @@
                 
                 var action = new SigAction(
                     name,
-                    (bamf_app == null) ? application.get_icon_name().down() : bamf_app.get_icon(),
+                    //(bamf_app == null) ? application.get_icon_name().down() : bamf_app.get_icon(),
+                    application.get_icon_name().down(),
                     "%lu".printf(window.get_xid()) 
                 );
                 action.activated.connect(() => {
