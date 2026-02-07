--- src/startup.c.orig	2015-08-11 18:41:14 UTC
+++ src/startup.c
@@ -666,7 +666,7 @@ void StartUp(Bool defaultScreenOnly)
 		wMenuRestoreState(wScreen[j]);
 
 		/* If we're not restarting, restore session */
-		if (wPreferences.flags.restarting == 0 && !wPreferences.flags.norestore)
+		if (!wPreferences.flags.restarting && !wPreferences.flags.norestore)
 			wSessionRestoreState(wScreen[j]);
 
 		if (!wPreferences.flags.noautolaunch) {
