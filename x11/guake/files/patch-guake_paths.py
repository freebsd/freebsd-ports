--- guake/paths.py.orig	2018-10-09 15:31:40 UTC
+++ guake/paths.py
@@ -35,7 +35,7 @@ def get_default_package_root():
 
 
 def get_data_files_dir():
-    d = os.path.dirname(os.path.dirname(sys.modules["guake"].__file__))
+    d = os.path.dirname(sys.modules["guake"].__file__)
     p = os.path.basename(os.path.abspath(os.path.join(d, "..")))
     if p in ["site-packages", "dist-packages"]:
         # current "guake" package has been installed in a prefix structure (/usr, /usr/local or
