--- src/Screen.cc.orig	2008-11-17 11:30:06.000000000 -0800
+++ src/Screen.cc	2008-11-17 11:31:37.000000000 -0800
@@ -1870,11 +1870,12 @@
 
   if (event->message_type == _blackbox->ewmh().numberOfDesktops()) {
     unsigned int number = event->data.l[0];
-    if (number > workspaceCount()) {
-      for (; number != workspaceCount(); --number)
+    unsigned int wsCount = workspaceCount();
+    if (number > wsCount) {
+      for (; number != wsCount; --number)
         addWorkspace();
-    } else if (number < workspaceCount()) {
-      for (; number != workspaceCount(); ++number)
+    } else if (number < wsCount) {
+      for (; number != wsCount; ++number)
         removeLastWorkspace();
     }
   } else if (event->message_type == _blackbox->ewmh().desktopNames()) {
