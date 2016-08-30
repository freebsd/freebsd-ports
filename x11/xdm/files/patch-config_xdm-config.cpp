--- config/xdm-config.cpp.orig	2011-09-25 07:35:47 UTC
+++ config/xdm-config.cpp
@@ -31,6 +31,7 @@ DisplayManager*authComplain:	true
 DisplayManager._0.setup:	XDMSCRIPTDIR/Xsetup_0
 DisplayManager._0.startup:	XDMSCRIPTDIR/GiveConsole
 DisplayManager._0.reset:	XDMSCRIPTDIR/TakeConsole
+DisplayManager.*.authName:     MIT-MAGIC-COOKIE-1
 #ifdef XPM
 DisplayManager*loginmoveInterval:	10
 #endif /* XPM */
