--- ./src/fluxbox.hh.orig	2013-02-13 10:04:05.899812000 +0000
+++ ./src/fluxbox.hh	2013-09-20 15:41:23.585087645 +0000
@@ -88,7 +88,7 @@
     /// main event loop
     void eventLoop();
     bool validateWindow(Window win) const;
-    bool validateClient(const WinClient *client) const;
+    bool validateClient(WinClient *client) const;
 
     void grab();
     void ungrab();
