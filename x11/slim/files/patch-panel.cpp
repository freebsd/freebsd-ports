--- panel.cpp.orig	2013-10-01 22:38:05 UTC
+++ panel.cpp
@@ -48,7 +48,7 @@ Panel::Panel(Display* dpy, int scr, Wind
 		gcm = GCGraphicsExposures;
 		gcv.graphics_exposures = False;
 		WinGC = XCreateGC(Dpy, Win, gcm, &gcv);
-		if (WinGC < 0) {
+		if (WinGC == NULL) {
 			cerr << APPNAME
 				<< ": failed to create pixmap\n.";
 			exit(ERR_EXIT);
