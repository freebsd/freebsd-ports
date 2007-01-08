--- kwin/client.cpp.orig	Mon Oct  2 03:02:07 2006
+++ kwin/client.cpp	Mon Jan  8 10:54:19 2007
@@ -477,17 +477,30 @@
     // calls it or when the decoration is created/destroyed
 
     if( Shape::version() >= 0x11 ) // 1.1, has input shape support
-        { // there appears to be no way to find out if a window has input
-          // shape set or not, so always set propagate the input shape
-          // (it's the same like the bounding shape by default)
-        XShapeCombineShape( qt_xdisplay(), frameId(), ShapeInput, 0, 0,
+        { // There appears to be no way to find out if a window has input 
+          // shape set or not, so always propagate the input shape 
+          // (it's the same like the bounding shape by default). 
+          // Also, build the shape using a helper window, not directly 
+          // in the frame window, because the sequence set-shape-to-frame, 
+          // remove-shape-of-client, add-input-shape-of-client has the problem 
+          // that after the second step there's a hole in the input shape 
+          // until the real shape of the client is added and that can make 
+          // the window lose focus (which is a problem with mouse focus policies) 
+        static Window helper_window = None; 
+        if( helper_window == None ) 
+            helper_window = XCreateSimpleWindow( qt_xdisplay(), qt_xrootwin(), 
+                0, 0, 1, 1, 0, 0, 0 ); 
+        XResizeWindow( qt_xdisplay(), helper_window, width(), height()); 
+        XShapeCombineShape( qt_xdisplay(), helper_window, ShapeInput, 0, 0, 
                            frameId(), ShapeBounding, ShapeSet );
-        XShapeCombineShape( qt_xdisplay(), frameId(), ShapeInput,
+        XShapeCombineShape( qt_xdisplay(), helper_window, ShapeInput, 
                            clientPos().x(), clientPos().y(),
                            window(), ShapeBounding, ShapeSubtract );
-        XShapeCombineShape( qt_xdisplay(), frameId(), ShapeInput,
+        XShapeCombineShape( qt_xdisplay(), helper_window, ShapeInput, 
                            clientPos().x(), clientPos().y(),
                            window(), ShapeInput, ShapeUnion );
+        XShapeCombineShape( qt_xdisplay(), frameId(), ShapeInput, 0, 0, 
+                           helper_window, ShapeInput, ShapeSet ); 
         }
     }
 
