--- src/utilities/bindingManager.vala.orig	2015-01-23 11:49:05 UTC
+++ src/utilities/bindingManager.vala
@@ -228,12 +228,12 @@ public class BindingManager : GLib.Objec
 
     private Gdk.FilterReturn event_filter(Gdk.XEvent gdk_xevent, Gdk.Event gdk_event) {
 
-        #if VALA_0_16 || VALA_0_17
-            X.Event* xevent = (X.Event*) gdk_xevent;
-        #else
+        //#if VALA_0_16 || VALA_0_17
+        //    X.Event* xevent = (X.Event*) gdk_xevent;
+        //#else
             void* pointer = &gdk_xevent;
             X.Event* xevent = (X.Event*) pointer;
-        #endif
+        //#endif
 
         if(xevent->type == X.EventType.KeyPress) {
             foreach(var binding in bindings) {
