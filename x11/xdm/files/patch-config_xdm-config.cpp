--- config/xdm-config.cpp.orig	2011-09-25 07:35:47 UTC
+++ config/xdm-config.cpp
@@ -12,25 +12,26 @@
 DisplayManager.authDir:	XDMXAUTHDIR
 DisplayManager.errorLogFile:	XDMLOGDIR/xdm.log
 DisplayManager.pidFile:		XDMPIDDIR/xdm.pid
-DisplayManager.keyFile:		XDMCONFIGDIR/xdm-keys
-DisplayManager.servers:		XDMCONFIGDIR/Xservers
-DisplayManager.accessFile:	XDMCONFIGDIR/Xaccess
-DisplayManager*resources:	XDMCONFIGDIR/Xresources
-DisplayManager.willing:		SU nobody -s /bin/sh -c XDMSCRIPTDIR/Xwilling
+DisplayManager.keyFile:		/usr/local/lib/X11/xdm/xdm-keys
+DisplayManager.servers:		/usr/local/lib/X11/xdm/Xservers
+DisplayManager.accessFile:	/usr/local/lib/X11/xdm/Xaccess
+DisplayManager*resources:	/usr/local/lib/X11/xdm/Xresources
+DisplayManager.willing:		SU nobody -s /bin/sh -c /usr/local/lib/X11/xdm/Xwilling
 ! All displays should use authorization, but we cannot be sure
 ! X terminals may not be configured that way, so they will require
 ! individual resource settings.
 DisplayManager*authorize:	true
 !
 DisplayManager*chooser:		CHOOSERPATH
-DisplayManager*startup:		XDMSCRIPTDIR/Xstartup
-DisplayManager*session:		XDMSCRIPTDIR/Xsession
-DisplayManager*reset:		XDMSCRIPTDIR/Xreset
+DisplayManager*startup:		/usr/local/lib/X11/xdm/Xstartup
+DisplayManager*session:		/usr/local/lib/X11/xdm/Xsession
+DisplayManager*reset:		/usr/local/lib/X11/xdm/Xreset
 DisplayManager*authComplain:	true
 ! The following three resources set up display :0 as the console.
-DisplayManager._0.setup:	XDMSCRIPTDIR/Xsetup_0
-DisplayManager._0.startup:	XDMSCRIPTDIR/GiveConsole
-DisplayManager._0.reset:	XDMSCRIPTDIR/TakeConsole
+DisplayManager._0.setup:	/usr/local/lib/X11/xdm/Xsetup_0
+DisplayManager._0.startup:	/usr/local/lib/X11/xdm/GiveConsole
+DisplayManager._0.reset:	/usr/local/lib/X11/xdm/TakeConsole
+DisplayManager.*.authName:     MIT-MAGIC-COOKIE-1
 #ifdef XPM
 DisplayManager*loginmoveInterval:	10
 #endif /* XPM */
