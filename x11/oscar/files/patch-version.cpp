When building port, ensure that version always resolve to
the same app name

--- version.cpp.orig	2026-10-31 09:48:51 UTC
+++ version.cpp
@@ -63,6 +63,7 @@ QString getPrereleaseSuffix()
 #endif
     }
 
+    suffix = "";
     return suffix;
 }
 
