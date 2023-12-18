--- src/OBPager.h.orig	2004-09-01 14:23:44 UTC
+++ src/OBPager.h
@@ -63,7 +63,7 @@ class OBPager
 		~OBPager();
 		
 		/// Connect to a specified X server display, or the default display
-		void connectToXServer(char *displayName = NULL);
+		void connectToXServer(const char *displayName = NULL);
 		
 		/// Create and show the X window
 		void createShowWindow();
