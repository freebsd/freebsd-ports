--- bbapm.cc.orig	Fri Dec  7 19:42:46 2001
+++ bbapm.cc	Fri Dec  7 19:42:57 2001
@@ -28,6 +28,9 @@
 ToolWindow::ToolWindow(int argc, char **argv):
 Basewindow(argc, argv)
 {
+    resource = NULL;
+    load = NULL;
+
     close_app = False;
     broken = False; 
