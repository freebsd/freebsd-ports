--- WPrefs.app/Paths.c.orig	2023-01-06 21:34:50 UTC
+++ WPrefs.app/Paths.c
@@ -78,10 +78,9 @@ static void showData(_Panel * panel)
 			wwarning(_("bad value in option IconPath. Using default path list"));
 		addPathToList(panel->icoL, -1, "~/pixmaps");
 		addPathToList(panel->icoL, -1, "~/" GSUSER_SUBDIR "/" USERDATA_SUBDIR "/Icons");
-		addPathToList(panel->icoL, -1, "/usr/include/X11/pixmaps");
-		addPathToList(panel->icoL, -1, "/usr/local/share/" PACKAGE_TARNAME "/Icons");
-		addPathToList(panel->icoL, -1, "/usr/local/share/" PACKAGE_TARNAME "/Pixmaps");
-		addPathToList(panel->icoL, -1, "/usr/share/" PACKAGE_TARNAME "/Icons");
+		addPathToList(panel->icoL, -1, PREFIX "/share/pixmaps");
+		addPathToList(panel->icoL, -1, PREFIX "/share/" PACKAGE_TARNAME "/Icons");
+		addPathToList(panel->icoL, -1, PREFIX "/share/" PACKAGE_TARNAME "/Pixmaps");
 	} else {
 		for (i = 0; i < WMGetPropListItemCount(array); i++) {
 			val = WMGetFromPLArray(array, i);
@@ -95,7 +94,7 @@ static void showData(_Panel * panel)
 			wwarning(_("bad value in option PixmapPath. Using default path list"));
 		addPathToList(panel->pixL, -1, "~/pixmaps");
 		addPathToList(panel->pixL, -1, "~/" GSUSER_SUBDIR "/" USERDATA_SUBDIR "/" PACKAGE_TARNAME "/Pixmaps");
-		addPathToList(panel->pixL, -1, "/usr/local/share/" PACKAGE_TARNAME "/Pixmaps");
+		addPathToList(panel->pixL, -1, PREFIX "/share/" PACKAGE_TARNAME "/Pixmaps");
 	} else {
 		for (i = 0; i < WMGetPropListItemCount(array); i++) {
 			val = WMGetFromPLArray(array, i);
