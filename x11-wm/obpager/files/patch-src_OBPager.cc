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
 	
@@ -397,7 +397,7 @@ void OBPager::createShowWindow()
 	
 	// First, get the mask as an XBM, and hold it in an auto_ptr so it gets disposed when we exit this block
 	
-	std::auto_ptr<unsigned char> pixmaskBits(getRectangularXBMMask(width, height, APPLET_MARGIN_WIDTH));
+	std::unique_ptr<unsigned char> pixmaskBits(getRectangularXBMMask(width, height, APPLET_MARGIN_WIDTH));
 	
 	// Next, create the pixmap using the XBM mask
 	
@@ -934,7 +934,8 @@ void OBPager::redrawWindow()
 	
 	// Draw the desktop number using the appropriate font
 	
-	char text[2] = { (mDesktopNum % 9) + '1', '\0' };
+	char text[4];
+	snprintf(text, sizeof text, "%d", mDesktopNum + 1);
 	int textLength = strlen(text);
 	int textWidth, textHeight;
 	int direction, ascent, descent;
