--- winpinmenu.c.orig	2013-09-17 21:38:07.462238988 -0700
+++ winpinmenu.c	2013-09-17 22:08:56.640738874 -0700
@@ -91,7 +91,7 @@
     WinPinMenu		*winInfo;
 {
     if (! StartMenuGrabs(dpy, winInfo))
-	return;
+	return 0;
 
     MenuMakeFirst(winInfo->menuInfo, afterMenuShow, winInfo);
 
@@ -109,7 +109,7 @@
 
     if (MenuHandleKeyEvent(dpy, event, winInfo, winInfo)) {
 	if (! StartMenuGrabs(dpy, winInfo))
-	    return;
+	    return 0;
     }
 }
 
