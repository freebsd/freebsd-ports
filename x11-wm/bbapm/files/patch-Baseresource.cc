--- Baseresource.cc.orig	Mon Aug 16 10:40:24 1999
+++ Baseresource.cc	Sat Aug  4 20:52:40 2001
@@ -27,6 +27,9 @@
 {
     bbtool = toolwindow;
 
+    style.conf_filename = NULL;
+    style.style_filename = NULL;
+
     if (bbtool->default_config) {
 	ReadDefaultResource();
 	ResourceType = DEFAULT;
