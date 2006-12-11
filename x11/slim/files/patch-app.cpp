--- app.cpp.orig	Fri Nov 24 16:36:58 2006
+++ app.cpp	Sun Nov 26 23:14:35 2006
@@ -560,13 +560,6 @@ int App::StartServer() {
         } else if (pos == 0) {
             server[argc++] = args+pos;
         }
-        if (server[argc-1][0] == 'v' && server[argc-1][1] == 't') {
-            bool ok = false;
-            Cfg::string2int(server[argc-1]+2, &ok);
-            if (ok) {
-                hasVtSet = true;
-            }
-        }
         ++pos;
 
         if (argc+1 >= MAX_XSERVER_ARGS) {
@@ -576,8 +569,19 @@ int App::StartServer() {
             break;
         }
     }
+
+    for (int i=0; i<argc; i++) {
+        if (server[i][0] == 'v' && server[i][1] == 't') {
+            bool ok = false;
+            Cfg::string2int(server[i]+2, &ok);
+            if (ok) {
+                hasVtSet = true;
+            }
+        }
+    }
+
     if (!hasVtSet && daemonmode) {
-        server[argc++] = "vt07";
+        server[argc++] = "vt09";
     }
     server[argc] = NULL;
 
