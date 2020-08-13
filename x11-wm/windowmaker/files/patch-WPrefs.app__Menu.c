--- WPrefs.app/Menu.c.orig	2020-04-05 13:41:15 UTC
+++ WPrefs.app/Menu.c
@@ -518,19 +518,19 @@ static void createPanel(_Panel * p)
 		data = putNewItem(panel, pad, DirectoryInfo, _("Themes"));
 		data->param.directory.command = "setstyle";
 		data->param.directory.directory =
-		    "/usr/share/WindowMaker/Themes /usr/local/share/WindowMaker/Themes $HOME/GNUstep/Library/WindowMaker/Themes";
+		    "/usr/share/WindowMaker/Themes " PREFIX "/share/WindowMaker/Themes $HOME/GNUstep/Library/WindowMaker/Themes";
 		data->param.directory.stripExt = 1;
 
 		data = putNewItem(panel, pad, DirectoryInfo, _("Bg Images (scale)"));
 		data->param.directory.command = "wmsetbg -u -s";
 		data->param.directory.directory =
-		    "/opt/kde2/share/wallpapers /usr/share/WindowMaker/Backgrounds $HOME/GNUstep/Library/WindowMaker/Backgrounds";
+		    "/opt/kde2/share/wallpapers " PREFIX "/share/WindowMaker/Backgrounds $HOME/GNUstep/Library/WindowMaker/Backgrounds";
 		data->param.directory.stripExt = 1;
 
 		data = putNewItem(panel, pad, DirectoryInfo, _("Bg Images (tile)"));
 		data->param.directory.command = "wmsetbg -u -t";
 		data->param.directory.directory =
-		    "/opt/kde2/share/wallpapers /usr/share/WindowMaker/Backgrounds $HOME/GNUstep/Library/WindowMaker/Backgrounds";
+		    "/opt/kde2/share/wallpapers " PREFIX "/share/WindowMaker/Backgrounds $HOME/GNUstep/Library/WindowMaker/Backgrounds";
 		data->param.directory.stripExt = 1;
 
 		smenu = putNewSubmenu(pad, _("Assorted XTerms"));
