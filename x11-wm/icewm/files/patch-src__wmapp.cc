--- src/wmapp.cc.orig
+++ src/wmapp.cc
@@ -337,7 +337,7 @@
             int ndirs; // ------------------- retrieve the old X's font path ---
             char ** fontPath(XGetFontPath(xapp->display(), &ndirs));
 
-            char ** newFontPath = new char *[ndirs + 1];
+            const char ** newFontPath = new const char *[ndirs + 1];
             newFontPath[ndirs] = fontsdir;
 
             if (fontPath)
@@ -383,7 +383,7 @@
             XChangeProperty(xapp->display(), manager->handle(),
                             XA_ICEWM_FONT_PATH, XA_STRING, 8, PropModeReplace,
                             (unsigned char *) fontsdir, strlen(fontsdir));
-            XSetFontPath(xapp->display(), newFontPath, ndirs + 1);
+            XSetFontPath(xapp->display(), (char **) newFontPath, ndirs + 1);
 
             if (fontPath) XFreeFontPath(fontPath);
             delete[] fontsdir;
