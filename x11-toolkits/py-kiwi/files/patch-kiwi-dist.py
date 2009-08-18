--- kiwi/dist.py	2009-07-14 19:01:15.000000000 +0200
+++ kiwi/dist.py.port	2009-08-18 10:28:06.000000000 +0200
@@ -159,7 +159,7 @@
     python_version = sys.version_info[:2]
     libdir = get_python_lib(plat_specific=False,
                             standard_lib=True, prefix='')
-    if python_version < (2, 6):
+    if python_version <= (2, 6):
         site = 'site-packages'
     else:
         site = 'dist-packages'
