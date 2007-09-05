--- ./src/yxtray.cc.orig	Tue Aug  7 02:12:03 2007
+++ ./src/yxtray.cc	Tue Sep  4 23:56:16 2007
@@ -133,7 +133,7 @@
 
 void YXTrayEmbedder::configure(const YRect &r, const bool resized) {
     YXEmbed::configure(r, resized);
-    fDocked->setGeometry(r);
+    fDocked->setSize(r.width(), r.height());
 }
 
 void YXTrayEmbedder::handleConfigureRequest(const XConfigureRequestEvent &configureRequest)
