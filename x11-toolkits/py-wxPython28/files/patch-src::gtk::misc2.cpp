
$FreeBSD$

--- src/gtk/misc2.cpp	2001/05/28 18:13:20	1.1
+++ src/gtk/misc2.cpp	2001/05/28 18:13:40
@@ -221,7 +221,7 @@
     int GetUPosition() { return -1; }
     int GetVPosition() { return -1; }
     int GetMovementThreshold() { return -1; }
-    void SetMovementThreshold(int threshold) ;
+    void SetMovementThreshold(int threshold) { return; };
 
     bool IsOk(void) { return FALSE; }
     int GetNumberJoysticks() { return -1; }
