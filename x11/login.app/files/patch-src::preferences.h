--- src/preferences.h.orig	Sun Oct 24 04:15:32 2004
+++ src/preferences.h	Sat Jan  8 18:26:20 2005
@@ -47,7 +47,7 @@
 #endif
 #define DEFAULT_POWEROFFMESSAGE		"System is shutting down..."
 #define DEFAULT_RESTARTMESSAGE		"System is rebooting..."
-#define DEFAULT_XSERVER			"/usr/X11R6/bin/X"
+#define DEFAULT_XSERVER			"%%X11BASE%%/bin/X"
 #define DEFAULT_THEME			"Drone"
 #define DEFAULT_DISABLEWELCOMEMESSAGE	True
 #define DEFAULT_DISABLEUSERSHUTDOWN	False
