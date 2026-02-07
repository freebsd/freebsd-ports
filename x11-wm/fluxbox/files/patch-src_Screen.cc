--- src/Screen.cc.orig	2015-02-08 10:44:45 UTC
+++ src/Screen.cc
@@ -297,7 +297,7 @@ BScreen::BScreen(FbTk::ResourceManager &rm,
                             "using visual 0x%lx, depth %d\n",
                             "informational message saying screen number (%d), visual (%lx), and colour depth (%d)").c_str(),
             screenNumber(), XVisualIDFromVisual(rootWindow().visual()),
-            rootWindow().depth());
+            rootWindow().maxDepth());
 #endif // DEBUG
 
     FbTk::EventManager *evm = FbTk::EventManager::instance();
