--- src/utilities/bindingManager.vala.orig	2021-07-17 09:00:37 UTC
+++ src/utilities/bindingManager.vala
@@ -341,12 +341,12 @@ public class BindingManager : GLib.Object {
 
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
 
 
         if (xevent->type == X.EventType.KeyPress) {
