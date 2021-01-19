--- setup.py.orig	2021-01-01 14:03:23 UTC
+++ setup.py
@@ -7,13 +7,16 @@ from setuptools import setup
 
 
 def get_data_files():
+    # Let FreeBSD port handle glib schema file to avoid plist error
+    black_list = ['net.launchpad.caffeine.gschema.xml']
     data_files = []
 
     for path, _dirs, files in walk("share"):
         target_path = os.path.join("/usr", path)
 
-        if files:
-            data_files.append((target_path, [os.path.join(path, f) for f in files]))
+        tl = [os.path.join(path, f) for f in files if f not in black_list]
+        if tl:
+            data_files.append((target_path, tl))
 
     # Install all icons for the package into /usr/share as well.
     # This is because the .desktop file actually uses them too.
