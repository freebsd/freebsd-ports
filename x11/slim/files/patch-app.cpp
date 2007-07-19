--- app.cpp.orig	Sun Jul 15 16:09:28 2007
+++ app.cpp	Wed Jul 18 20:28:27 2007
@@ -135,6 +135,7 @@
     ServerPID = -1;
     testing = false;
     mcookie = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
+    daemonmode = false;
     Dpy = NULL;
 
     // Parse command line
@@ -858,7 +859,7 @@
     }
 
     if (!hasVtSet && daemonmode) {
-        server[argc++] = "vt07";
+        server[argc++] = "vt09";
     }
     server[argc] = NULL;
 
