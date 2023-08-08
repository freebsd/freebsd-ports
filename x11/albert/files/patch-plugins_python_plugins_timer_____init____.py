--- plugins/python/plugins/timer/__init__.py.orig	2023-02-05 15:51:51 UTC
+++ plugins/python/plugins/timer/__init__.py
@@ -65,7 +65,8 @@ class Plugin(QueryHandler):
             subprocess.Popen(["aplay", self.soundPath])
         elif platform == "darwin":
             subprocess.Popen(["afplay", self.soundPath])
-
+        else:
+            subprocess.Popen(["play", self.soundPath])
         self.deleteTimer(timer)
 
     def id(self):
@@ -130,4 +131,4 @@ class Plugin(QueryHandler):
             ))
 
         if items:
-            query.add(items)
\ No newline at end of file
+            query.add(items)
