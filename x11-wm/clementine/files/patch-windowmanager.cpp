$FreeBSD$

windowmanager.cpp: In method `void WindowManager::takeButtonPress(long unsigned int, unsigned int, bool, int, int)':
windowmanager.cpp:309: implicit declaration of function `int dumpClients(...)'

--- windowmanager.cpp.orig	Sun May 26 01:54:11 2002
+++ windowmanager.cpp	Sun May 26 03:34:46 2002
@@ -306,7 +306,9 @@ void WindowManager::takeButtonPress( Win
 	c->redraw( true );
 	clients.push_back( c );
 	icons.erase( std::find( icons.begin(), icons.end(), c ) );
+#ifdef DEBUG
 	dumpClients();
+#endif
     } else {
 	if ( menu ) {
 	    delete menu;
