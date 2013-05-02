--- src/startup.c.orig	2013-01-10 06:42:39.000000000 +0900
+++ src/startup.c	2013-05-03 03:30:24.000000000 +0900
@@ -758,7 +758,7 @@
 		wMenuRestoreState(wScreen[j]);
 
 		/* If we're not restarting, restore session */
-		if (wPreferences.flags.restarting == 0 && !wPreferences.flags.norestore)
+		if (!wPreferences.flags.restarting && !wPreferences.flags.norestore)
 			wSessionRestoreState(wScreen[j]);
 
 		if (!wPreferences.flags.noautolaunch) {
