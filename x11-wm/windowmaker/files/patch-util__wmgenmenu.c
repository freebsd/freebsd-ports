--- util/wmgenmenu.c.orig	2013-01-10 06:42:39.000000000 +0900
+++ util/wmgenmenu.c	2013-05-03 03:21:14.000000000 +0900
@@ -146,7 +146,7 @@
 	L2Menu = WMCreatePLArray(
 		WMCreatePLString(_("Themes")),
 		WMCreatePLString("OPEN_MENU"),
-		WMCreatePLString("-noext /usr/local/share/WindowMaker/Themes $HOME/GNUstep/Library/WindowMaker/Themes WITH setstyle"),
+		WMCreatePLString("-noext " PREFIX "/share/WindowMaker/Themes $HOME/GNUstep/Library/WindowMaker/Themes WITH setstyle"),
 		NULL
 	);
 	WMAddToPLArray(L1Menu, L2Menu);
@@ -155,7 +155,7 @@
 	L2Menu = WMCreatePLArray(
 		WMCreatePLString(_("Styles")),
 		WMCreatePLString("OPEN_MENU"),
-		WMCreatePLString("-noext /usr/local/share/WindowMaker/Styles $HOME/GNUstep/Library/WindowMaker/Styles WITH setstyle"),
+		WMCreatePLString("-noext " PREFIX "/share/WindowMaker/Styles $HOME/GNUstep/Library/WindowMaker/Styles WITH setstyle"),
 		NULL
 	);
 	WMAddToPLArray(L1Menu, L2Menu);
@@ -164,7 +164,7 @@
 	L2Menu = WMCreatePLArray(
 		WMCreatePLString(_("Icon Sets")),
 		WMCreatePLString("OPEN_MENU"),
-		WMCreatePLString("-noext /usr/local/share/WindowMaker/IconSets $HOME/GNUstep/Library/WindowMaker/IconSets WITH seticons"),
+		WMCreatePLString("-noext " PREFIX "/share/WindowMaker/IconSets $HOME/GNUstep/Library/WindowMaker/IconSets WITH seticons"),
 		NULL
 	);
 	WMAddToPLArray(L1Menu, L2Menu);
@@ -321,7 +321,7 @@
 	L1Menu = WMCreatePLArray(
 		WMCreatePLString(_("Configure Window Maker")),
 		WMCreatePLString("EXEC"),
-		WMCreatePLString("WPrefs"),
+		WMCreatePLString(PREFIX "/GNUstep/Applications/WPrefs.app/WPrefs"),
 		NULL
 	);
 	WMAddToPLArray(RMenu, L1Menu);
