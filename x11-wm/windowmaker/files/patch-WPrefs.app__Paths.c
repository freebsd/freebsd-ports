--- WPrefs.app/Paths.c.orig	2015-08-11 18:41:14 UTC
+++ WPrefs.app/Paths.c
@@ -78,9 +78,9 @@ static void showData(_Panel * panel)
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
@@ -95,7 +95,7 @@ static void showData(_Panel * panel)
 			wwarning(_("bad value in option PixmapPath. Using default path list"));
 		addPathToList(panel->pixL, -1, "~/pixmaps");
 		addPathToList(panel->pixL, -1, "~/GNUstep/Library/WindowMaker/Pixmaps");
-		addPathToList(panel->pixL, -1, "/usr/local/share/WindowMaker/Pixmaps");
+		addPathToList(panel->pixL, -1, PREFIX "/share/WindowMaker/Pixmaps");
 	} else {
 		for (i = 0; i < WMGetPropListItemCount(array); i++) {
 			val = WMGetFromPLArray(array, i);
