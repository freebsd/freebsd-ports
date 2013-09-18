--- clients/olwm/winpinmenu.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/winpinmenu.c	2013-09-17 23:08:47.322025297 -0700
@@ -87,7 +87,7 @@
     WinPinMenu		*winInfo;
 {
     if (! StartMenuGrabs(dpy, winInfo))
-	return;
+	return 0;
 
     MenuMakeFirst(winInfo->menuInfo, afterMenuShow, winInfo);
 
@@ -105,7 +105,7 @@
 
     if (MenuHandleKeyEvent(dpy, event, winInfo, winInfo)) {
 	if (! StartMenuGrabs(dpy, winInfo))
-	    return;
+	    return 0;
     }
 }
 
