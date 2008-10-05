--- app.cpp.orig	2008-10-04 13:45:58.000000000 +0200
+++ app.cpp	2008-10-04 13:46:07.000000000 +0200
@@ -887,7 +887,7 @@
     }
 
     if (!hasVtSet && daemonmode) {
-        server[argc++] = (char*)"vt07";
+        server[argc++] = (char*)"vt09";
     }
     server[argc] = NULL;
 
