When building port, ensure that version always resolve to
the same app name

--- version.cpp
+++ version.cpp
@@ -63,6 +63,7 @@ QString getPrereleaseSuffix()
 #endif
     }
 
+    suffix = "";
     return suffix;
 }
 
