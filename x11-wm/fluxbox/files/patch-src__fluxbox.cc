--- src/fluxbox.cc.orig	2015-02-08 10:44:45 UTC
+++ src/fluxbox.cc
@@ -1316,7 +1316,7 @@ void Fluxbox::revertFocus() {
         FocusControl::setFocusedWindow(0);
 }
 
-bool Fluxbox::validateClient(const WinClient *client) const {
+bool Fluxbox::validateClient(WinClient *client) const {
     WinClientMap::const_iterator it =
         find_if(m_window_search.begin(),
                 m_window_search.end(),
