--- windowmanager.cc.orig	2005-01-03 21:54:59 UTC
+++ windowmanager.cc
@@ -51,24 +51,24 @@ WindowManager::WindowManager(int argc, char** argv)
 	// Set the global window manager object to this please =)
     	wm = this;
 	
-	window_manager_name="jewel";
+	window_manager_name=(char *)"jewel";
 
 	// Make the default options equal something
-    	opt_font = DEF_FONT;
-	opt_fm = DEF_FM;
-    	opt_fg = DEF_FG;
-    	opt_fc = DEF_FC;
-    	opt_bg = DEF_BG;
-    	opt_bd = DEF_BD;
-    	opt_tj = TEXT_JUSTIFY;
-	opt_wm = WIRE_MOVE;
-	opt_es = EDGE_SNAP;
-	opt_newkey = DEF_NEWKEY;
-    	opt_new1 = DEF_NEW1;
-    	opt_new2 = DEF_NEW2;
+    	opt_font = (char *)DEF_FONT;
+	   opt_fm = (char *)DEF_FM;
+    	opt_fg = (char *)DEF_FG;
+    	opt_fc = (char *)DEF_FC;
+    	opt_bg = (char *)DEF_BG;
+    	opt_bd = (char *)DEF_BD;
+    	opt_tj = (char *)TEXT_JUSTIFY;
+	   opt_wm = (char *)WIRE_MOVE;
+	   opt_es = (char *)EDGE_SNAP;
+	   opt_newkey = (char *)DEF_NEWKEY;
+    	opt_new1 = (char *)DEF_NEW1;
+    	opt_new2 = (char *)DEF_NEW2;
     	opt_bw = DEF_BW;
     	opt_display=NULL;
-	maxDesktops=MAX_DESKTOPS;
+	   maxDesktops=MAX_DESKTOPS;
 
 // These macro's are nice to test values passed in 
 // the command line arguments	
@@ -1557,21 +1557,21 @@ void WindowManager::focusNextWindowInStackingOrder()
 		// find the client in the list...
 		it = find(clientList->begin(), clientList->end(), c);
 
-		if ( it == NULL || it == clientList->end()) {
+		if ( it == clientList->end()) {
 			it = clientList->begin();
 		}
 
 		do {
 			cycles++;
-			if ( it != clientList->end() && it != NULL ) {
+			if ( it == clientList->end() ) {
+				it = clientList->begin();
+			}
+			else {
 				it++;
 				if ( it == clientList->end() ) {
 					it = clientList->begin();
 				}
 			}
-			else {
-				it = clientList->begin();
-			}
 		} while (cycles < clientList->size() && (shouldSkipThisWindow((*it)->getAppWindow()) || (*it)->isIconified() || (*it)->belongsToWhichDesktop() != currentDesktop));
 		
 #ifdef DEBUG
@@ -1588,7 +1588,7 @@ void WindowManager::focusNextWindowInStackingOrder()
 
 		// if we found a suitable "next client", raise and focus
 		// it; otherwise, leave focus where it is
-		if ( cycles < clientList->size() && it != NULL && it != clientList->end() && !shouldSkipThisWindow((*it)->getAppWindow()) && !(*it)->isIconified() && (*it)->belongsToWhichDesktop() == currentDesktop && !shouldSkipThisWindow((*it)->getAppWindow())) {
+		if ( cycles < clientList->size() && !(it == clientList->end()) && !shouldSkipThisWindow((*it)->getAppWindow()) && !(*it)->isIconified() && (*it)->belongsToWhichDesktop() == currentDesktop && !shouldSkipThisWindow((*it)->getAppWindow())) {
 			c = *it;
 			c->raise();
 			setFocusedClient(c);
