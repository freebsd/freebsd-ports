--- kwin/tabbox.cpp	2006/03/17 21:38:24	519807
+++ kwin/tabbox.cpp	2006/04/03 13:05:18	525954
@@ -1152,7 +1152,7 @@
 */
 Client* Workspace::nextFocusChainClient( Client* c ) const
     {
-    int desktop = c->isOnAllDesktops() ? currentDesktop() : c->desktop();
+    int desktop = !c || c->isOnAllDesktops() ? currentDesktop() : c->desktop();
     if ( focus_chain[desktop].isEmpty() )
         return 0;
     ClientList::ConstIterator it = focus_chain[desktop].find( c );
@@ -1170,7 +1170,7 @@
 */
 Client* Workspace::previousFocusChainClient( Client* c ) const
     {
-    int desktop = c->isOnAllDesktops() ? currentDesktop() : c->desktop();
+    int desktop = !c || c->isOnAllDesktops() ? currentDesktop() : c->desktop();
     if ( focus_chain[desktop].isEmpty() )
         return 0;
     ClientList::ConstIterator it = focus_chain[desktop].find( c );
