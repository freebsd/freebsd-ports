--- khtml/ecma/kjs_html.cpp	2007/02/26 16:39:44	637497
+++ khtml/ecma/kjs_html.cpp	2007/03/05 13:15:20	639609
@@ -1866,10 +1866,12 @@
 				      getDOMNode(exec, frameElement.contentDocument()) : Undefined();
     case FrameContentWindow:   {
         KHTMLPart* part = static_cast<DOM::HTMLFrameElementImpl*>(frameElement.handle())->contentPart();
-        if (part)
-            return Value(Window::retrieveWindow(part));
-        else
-            return Undefined();
+        if (part) {
+          Window *w = Window::retrieveWindow(part);
+          if (w)
+            return Value(w);
+        }
+        return Undefined();
     }
     case FrameFrameBorder:     return String(frameElement.frameBorder());
     case FrameLongDesc:        return String(frameElement.longDesc());
@@ -1899,10 +1901,12 @@
 				       getDOMNode(exec, iFrame.contentDocument()) : Undefined();
     case IFrameContentWindow:       {
         KHTMLPart* part = static_cast<DOM::HTMLIFrameElementImpl*>(iFrame.handle())->contentPart();
-        if (part)
-            return Value(Window::retrieveWindow(part));
-        else
-            return Undefined();
+        if (part) {
+          Window *w = Window::retrieveWindow(part);
+          if (w)
+            return Value(w);
+        }
+        return Undefined();
     }
     case IFrameFrameBorder:     return String(iFrame.frameBorder());
     case IFrameHeight:          return String(iFrame.height());
