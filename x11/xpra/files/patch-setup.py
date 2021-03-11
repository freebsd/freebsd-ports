--- setup.py.orig	2021-03-07 14:32:43 UTC
+++ setup.py
@@ -1012,7 +1012,7 @@ if 'clean' in sys.argv or 'sdist' in sys.argv:
     clean()
 
 def add_build_info(*args):
-    cmd = ["python3", "./fs/bin/add_build_info.py"]+list(args)
+    cmd = [sys.executable, "./fs/bin/add_build_info.py"]+list(args)
     r = subprocess.Popen(cmd).wait(30)
     assert r==0, "'%s' returned %s" % (" ".join(cmd), r)
 
@@ -1531,7 +1531,7 @@ else:
         add_data_files("%s/man1" % man_path,  man_pages)
         add_data_files("share/applications",  glob.glob("fs/share/applications/*.desktop"))
         add_data_files("share/mime/packages", ["fs/share/mime/packages/application-x-xpraconfig.xml"])
-        add_data_files("share/icons",         glob.glob("fs/share/icons/*.png"))
+        add_data_files("share/pixmaps",         glob.glob("fs/share/icons/*.png"))
         add_data_files("share/metainfo",      ["fs/share/metainfo/xpra.appdata.xml"])
 
     #here, we override build and install so we can
