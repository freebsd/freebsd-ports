--- src/OBPager.cc.orig	2004-09-01 14:23:44 UTC
+++ src/OBPager.cc
@@ -159,7 +159,7 @@ OBPager::~OBPager()
  * @param displayName is the name of the display to connect to
  */
 
-void OBPager::connectToXServer(char *displayName)
+void OBPager::connectToXServer(const char *displayName)
 {
 	// Connect to the user-specified desktop or whatever is in $DISPLAY?
 	
@@ -301,7 +301,7 @@ void OBPager::createShowWindow()
 	int maxHeight = height;
 	int minWidth = width;
 	int minHeight = height;
-	char* appName = APPLET_NAME;
+	char appName[] = APPLET_NAME;
 	unsigned long borderColour = BlackPixel(mDisplay(), mScreenNum);
 	unsigned long backgroundColour = BlackPixel(mDisplay(), mScreenNum);
 	
