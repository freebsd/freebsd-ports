--- resource.cc.orig	Tue Oct 15 21:10:51 2002
+++ resource.cc	Mon Jul 26 11:36:10 2004
@@ -23,6 +23,7 @@
 #include "blackboxstyle.hh"
 
 Resource::Resource(ToolWindow *toolwindow): BaseResource(toolwindow) {
+  frame.font = NULL;
   Load();
 }
 
