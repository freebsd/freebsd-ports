--- setup.py.orig	2018-05-17 01:08:07 UTC
+++ setup.py
@@ -7,14 +7,18 @@ from setuptools import find_packages, setup
 
 
 def get_data_files():
+    # Let FreeBSD port handle glib schema file to avoid plist error
+    black_list = ['net.launchpad.caffeine.gschema.xml']
     data_files = []
 
     for path, dirs, files in walk('share'):
         target_path = os.path.join('/usr', path)
 
-        data_files.append((
-            target_path, [os.path.join(path, f) for f in files]
-        ))
+        tl = [os.path.join(path, f) for f in files if f not in black_list]
+        if tl != []:
+            data_files.append((
+                target_path, tl
+            ))
 
     data_files.append(
         ("/etc/xdg/autostart", ["share/applications/caffeine.desktop"])
