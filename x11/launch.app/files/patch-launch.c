
$FreeBSD$

--- launch.c	2001/08/20 09:01:20	1.1
+++ launch.c	2001/08/20 09:02:33
@@ -208,8 +208,8 @@
 		WMSynchronizeUserDefaults (udb);
 		WMSetUDStringForKey (udb, "0.65", "Version");
 		WMSynchronizeUserDefaults (udb);
-		WMSetUDStringForKey (udb, "/usr/local/GNUstep/Apps/Launch.app/openurl %s", "HTTP_App");
-		WMSetUDStringForKey (udb, "/usr/local/GNUstep/Apps/Launch.app/openurl %s", "FTP_App");
+		WMSetUDStringForKey (udb, PREFIX "/Launch.app/openurl %s", "HTTP_App");
+		WMSetUDStringForKey (udb, PREFIX "/Launch.app/openurl %s", "FTP_App");
 		WMSetUDStringForKey (udb, "xterm -e %s", "Term_Com");
 		WMSetUDBoolForKey (udb, True, "Enable_Switch");
 		WMSynchronizeUserDefaults (udb);
@@ -220,8 +220,8 @@
 		{
 			WMSetUDStringForKey (udb, "0.65", "Version");
 			WMSynchronizeUserDefaults (udb);
-			WMSetUDStringForKey (udb, "/usr/local/GNUstep/Apps/Launch.app/openurl %s", "HTTP_App");
-			WMSetUDStringForKey (udb, "/usr/local/GNUstep/Apps/Launch.app/openurl %s", "FTP_App");
+			WMSetUDStringForKey (udb, PREFIX "/Launch.app/openurl %s", "HTTP_App");
+			WMSetUDStringForKey (udb, PREFIX "/Launch.app/openurl %s", "FTP_App");
 			WMSynchronizeUserDefaults (udb);
 			WMSaveUserDefaults (udb);
 		}
