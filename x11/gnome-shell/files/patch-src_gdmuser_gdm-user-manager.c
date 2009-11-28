--- src/gdmuser/gdm-user-manager.c.orig	2009-08-14 05:38:43.000000000 +0000
+++ src/gdmuser/gdm-user-manager.c	2009-08-14 05:39:14.000000000 +0000
@@ -1297,7 +1297,7 @@
                 }
         }
 
-        for (pwent = fgetpwent (fp); pwent != NULL; pwent = fgetpwent (fp)) {
+        for (pwent = getpwent(); pwent != NULL; pwent = getpwent()) {
                 GdmUser *user;
 
                 user = NULL;
