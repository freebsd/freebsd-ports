--- src/OBPager.h.orig	2014-02-14 15:36:36.000000000 +0100
+++ src/OBPager.h	2014-02-14 15:37:08.000000000 +0100
@@ -63,7 +63,7 @@
 		~OBPager();
 		
 		/// Connect to a specified X server display, or the default display
-		void connectToXServer(char *displayName = NULL);
+		void connectToXServer(const char *displayName = NULL);
 		
 		/// Create and show the X window
 		void createShowWindow();
