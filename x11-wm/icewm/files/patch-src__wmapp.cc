--- src/wmapp.cc.orig	2013-11-17 16:54:39 UTC
+++ src/wmapp.cc
@@ -221,7 +221,7 @@ static void registerProtocols2(Window xid) {
 #endif
 
     long pid = getpid();
-    const char wmname[] = "IceWM "VERSION" ("HOSTOS"/"HOSTCPU")";
+    const char wmname[] = "IceWM " VERSION " (" HOSTOS "/" HOSTCPU ")";
 
 #ifdef GNOME1_HINTS
     XChangeProperty(xapp->display(), xid, 
@@ -337,7 +337,7 @@ static void initFontPath(IApp *app) {
             int ndirs; // ------------------- retrieve the old X's font path ---
             char ** fontPath(XGetFontPath(xapp->display(), &ndirs));
 
-            char ** newFontPath = new char *[ndirs + 1];
+            const char ** newFontPath = new const char *[ndirs + 1];
             newFontPath[ndirs] = fontsdir;
 
             if (fontPath)
@@ -383,7 +383,7 @@ static void initFontPath(IApp *app) {
             XChangeProperty(xapp->display(), manager->handle(),
                             XA_ICEWM_FONT_PATH, XA_STRING, 8, PropModeReplace,
                             (unsigned char *) fontsdir, strlen(fontsdir));
-            XSetFontPath(xapp->display(), newFontPath, ndirs + 1);
+            XSetFontPath(xapp->display(), (char **) newFontPath, ndirs + 1);
 
             if (fontPath) XFreeFontPath(fontPath);
             delete[] fontsdir;
