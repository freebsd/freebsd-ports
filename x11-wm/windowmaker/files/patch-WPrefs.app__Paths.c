--- WPrefs.app/Paths.c.orig	2013-05-03 02:52:46.000000000 +0900
+++ WPrefs.app/Paths.c	2013-05-03 02:59:08.000000000 +0900
@@ -78,9 +78,9 @@
 			wwarning(_("bad value in option IconPath. Using default path list"));
 		addPathToList(panel->icoL, -1, "~/pixmaps");
 		addPathToList(panel->icoL, -1, "~/GNUstep/Library/Icons");
-		addPathToList(panel->icoL, -1, "/usr/include/X11/pixmaps");
-		addPathToList(panel->icoL, -1, "/usr/local/share/WindowMaker/Icons");
-		addPathToList(panel->icoL, -1, "/usr/local/share/WindowMaker/Pixmaps");
+		addPathToList(panel->icoL, -1, PREFIX "/share/pixmaps");
+		addPathToList(panel->icoL, -1, PREFIX "/share/WindowMaker/Icons");
+		addPathToList(panel->icoL, -1, PREFIX "/share/WindowMaker/Pixmaps");
 		addPathToList(panel->icoL, -1, "/usr/share/WindowMaker/Icons");
 	} else {
 		for (i = 0; i < WMGetPropListItemCount(array); i++) {
@@ -95,7 +95,7 @@
 			wwarning(_("bad value in option PixmapPath. Using default path list"));
 		addPathToList(panel->pixL, -1, "~/pixmaps");
 		addPathToList(panel->pixL, -1, "~/GNUstep/Library/WindowMaker/Pixmaps");
-		addPathToList(panel->pixL, -1, "/usr/local/share/WindowMaker/Pixmaps");
+		addPathToList(panel->pixL, -1, PREFIX "/share/WindowMaker/Pixmaps");
 	} else {
 		for (i = 0; i < WMGetPropListItemCount(array); i++) {
 			val = WMGetFromPLArray(array, i);
