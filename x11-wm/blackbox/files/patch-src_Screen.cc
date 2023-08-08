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
@@ -1927,12 +1928,12 @@ void BScreen::toggleFocusModel(FocusModel model) {
 
 void BScreen::toggleFocusModel(FocusModel model) {
   std::for_each(windowList.begin(), windowList.end(),
-                std::mem_fun(&BlackboxWindow::ungrabButtons));
+                std::mem_fn(&BlackboxWindow::ungrabButtons));
 
   _blackbox->resource().setFocusModel(model);
 
   std::for_each(windowList.begin(), windowList.end(),
-                std::mem_fun(&BlackboxWindow::grabButtons));
+                std::mem_fn(&BlackboxWindow::grabButtons));
 }
 
 
@@ -1976,7 +1977,7 @@ void BScreen::updateClientListHint(void) const {
   bt::EWMH::WindowList clientList(windowList.size());
 
   std::transform(windowList.begin(), windowList.end(), clientList.begin(),
-                 std::mem_fun(&BlackboxWindow::clientWindow));
+                 std::mem_fn(&BlackboxWindow::clientWindow));
 
   _blackbox->ewmh().setClientList(screen_info.rootWindow(), clientList);
 }
