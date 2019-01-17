--- FvwmCompositor/main/AScreen.cxx.orig	2008-11-25 10:22:45 UTC
+++ FvwmCompositor/main/AScreen.cxx
@@ -10,6 +10,7 @@
  *
  */
 
+#include <unistd.h>
 #ifdef HAVE_CONFIG_H
 #include "config-not-xserver.h"
 #endif
@@ -5159,7 +5160,7 @@ AScreen::AScreen(MetisseDesktop *metisseDesktop, bool 
 	_clipOpWaitForCtrlReleased = false;
 	_clipAutoRepeatOff = false;
 	_miIn = false;
-	_motionInterceptTk = false;
+	_motionInterceptTk = 0;
 	_miTkcount = 0;
 	_miFeed = 0;
 	_setupRightLongPressTimeOut();
