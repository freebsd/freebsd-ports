--- help-converters/info/main.c.orig	Mon Aug  5 14:06:06 2002
+++ help-converters/info/main.c	Wed Aug  7 01:52:35 2002
@@ -104,13 +104,15 @@
                 char buf[PATH_MAX];
 
                 /* First, find the directory that the info file is in. */
-                dirs[0] = "/usr/info";
-                dirs[1] = "/usr/share/info";
+		dirs[0] = "/usr/share/info";
+		dirs[1] = PREFIX "/info";
+		dirs[2] = LOCALBASE "/info";
+		dirs[3] = X11BASE "/info";
                 /* We now have at least one directory to look in. This is
                  * necessary because we may not have an 'INFOPATH' set */
-                ndirs = 2;
+                ndirs = 4;
                 if(infopath) {
-                        for (ndirs = 2, ctmp = strtok(infopath, ":"); ndirs < 64 && ctmp; ndirs++, ctmp = strtok(NULL, ":")) {
+                        for (ndirs = 4, ctmp = strtok(infopath, ":"); ndirs < 64 && ctmp; ndirs++, ctmp = strtok(NULL, ":")) {
                                 dirs[ndirs] = strdup(ctmp);
                         }
                 }
