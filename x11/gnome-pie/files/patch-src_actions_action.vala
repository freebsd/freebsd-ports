--- src/actions/action.vala.orig	2015-01-23 11:49:05 UTC
+++ src/actions/action.vala
@@ -63,7 +63,7 @@ public abstract class Action : GLib.Object {
     /// C'tor, initializes all members.
     /////////////////////////////////////////////////////////////////////
 
-    public Action(string name, string icon, bool is_quickaction) {
+    Action(string name, string icon, bool is_quickaction) {
         GLib.Object(name : name, icon : icon, is_quickaction : is_quickaction);
     }
 
