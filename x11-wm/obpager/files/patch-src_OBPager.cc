--- src/OBPager.cc.orig	2014-02-14 15:35:01.000000000 +0100
+++ src/OBPager.cc	2014-02-14 15:39:12.000000000 +0100
@@ -159,7 +159,7 @@
  * @param displayName is the name of the display to connect to
  */
 
-void OBPager::connectToXServer(char *displayName)
+void OBPager::connectToXServer(const char *displayName)
 {
 	// Connect to the user-specified desktop or whatever is in $DISPLAY?
 	
@@ -301,7 +301,7 @@
 	int maxHeight = height;
 	int minWidth = width;
 	int minHeight = height;
-	char* appName = APPLET_NAME;
+	char appName[] = APPLET_NAME;
 	unsigned long borderColour = BlackPixel(mDisplay(), mScreenNum);
 	unsigned long backgroundColour = BlackPixel(mDisplay(), mScreenNum);
 	
