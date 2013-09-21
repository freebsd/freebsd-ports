--- ./src/fluxbox.cc.orig	2013-02-13 10:04:05.899812000 +0000
+++ ./src/fluxbox.cc	2013-09-20 15:41:23.584087389 +0000
@@ -1355,7 +1355,7 @@
         FocusControl::setFocusedWindow(0);
 }
 
-bool Fluxbox::validateClient(const WinClient *client) const {
+bool Fluxbox::validateClient(WinClient *client) const {
     WinClientMap::const_iterator it =
         find_if(m_window_search.begin(),
                 m_window_search.end(),
