--- WPrefs.app/Menu.c.orig	2023-03-13 14:40:46 UTC
+++ WPrefs.app/Menu.c
@@ -520,8 +520,7 @@ static void createPanel(_Panel * p)
 		data = putNewItem(panel, pad, DirectoryInfo, _("Themes"));
 		data->param.directory.command = "setstyle";
 		data->param.directory.directory =
-		    "/usr/share/" PACKAGE_TARNAME "/Themes"
-		    " /usr/local/share/" PACKAGE_TARNAME "/Themes"
+		    PREFIX "/share/" PACKAGE_TARNAME "/Themes"
 		    " $HOME/" GSUSER_SUBDIR "/" USERDATA_SUBDIR "/" PACKAGE_TARNAME "/Themes";
 		data->param.directory.stripExt = 1;
 
@@ -529,7 +528,7 @@ static void createPanel(_Panel * p)
 		data->param.directory.command = "wmsetbg -u -s";
 		data->param.directory.directory =
 		    "/opt/kde2/share/wallpapers"
-		    " /usr/share/" PACKAGE_TARNAME "/Backgrounds"
+		    " " PREFIX "/share/" PACKAGE_TARNAME "/Backgrounds"
 		    " $HOME/" GSUSER_SUBDIR "/" USERDATA_SUBDIR "/" PACKAGE_TARNAME "/Backgrounds";
 		data->param.directory.stripExt = 1;
 
@@ -537,7 +536,7 @@ static void createPanel(_Panel * p)
 		data->param.directory.command = "wmsetbg -u -t";
 		data->param.directory.directory =
 		    "/opt/kde2/share/wallpapers"
-		    " /usr/share/" PACKAGE_TARNAME "/Backgrounds"
+		    " " PREFIX "/share/" PACKAGE_TARNAME "/Backgrounds"
 		    " $HOME/" GSUSER_SUBDIR "/" USERDATA_SUBDIR "/" PACKAGE_TARNAME "/Backgrounds";
 		data->param.directory.stripExt = 1;
 
