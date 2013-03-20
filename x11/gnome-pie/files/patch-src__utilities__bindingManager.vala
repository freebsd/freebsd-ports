--- ./src/utilities/bindingManager.vala.orig	2013-03-15 23:02:39.000000000 +0100
+++ ./src/utilities/bindingManager.vala	2013-03-15 23:03:13.000000000 +0100
@@ -228,12 +228,12 @@
     
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
