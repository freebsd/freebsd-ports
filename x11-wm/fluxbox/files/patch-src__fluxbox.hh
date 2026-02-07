--- src/fluxbox.hh.orig	2015-02-08 10:44:45 UTC
+++ src/fluxbox.hh
@@ -103,7 +103,7 @@ public:
     WinClient *searchWindow(Window);
     BScreen *searchScreen(Window w);
     bool validateWindow(Window win) const;
-    bool validateClient(const WinClient *client) const;
+    bool validateClient(WinClient *client) const;
 
     // Not currently implemented until we decide how it'll be used
     //WinClient *searchGroup(Window);
