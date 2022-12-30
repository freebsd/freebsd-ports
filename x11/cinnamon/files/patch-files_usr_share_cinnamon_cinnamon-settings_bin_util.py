--- files/usr/share/cinnamon/cinnamon-settings/bin/util.py.orig	2021-10-15 14:38:11 UTC
+++ files/usr/share/cinnamon/cinnamon-settings/bin/util.py
@@ -6,7 +6,7 @@ def strip_syspath_locals():
 
     new_path = []
     for path in sys.path:
-        if path.startswith(("/usr/local", os.path.expanduser("~/.local"))):
+        if path.startswith((os.path.expanduser("~/.local"))):
             continue
         new_path.append(path)
 
