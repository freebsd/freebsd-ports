--- src/Screen.cc.orig	2005-10-18 08:07:22 UTC
+++ src/Screen.cc
@@ -1870,11 +1870,12 @@ void BScreen::clientMessageEvent(const XClientMessageE
 
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
