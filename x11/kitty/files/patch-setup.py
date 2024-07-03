--- setup.py.orig	1979-11-29 23:00:00 UTC
+++ setup.py
@@ -1333,8 +1333,8 @@ def create_linux_bundle_gunk(ddir: str, args: Options)
     base = Path(ddir)
     in_src_launcher = base / (f'{libdir_name}/kitty/kitty/launcher/kitty')
     launcher = base / 'bin/kitty'
-    skip_docs = False
-    if not os.path.exists('docs/_build/html'):
+    skip_docs = os.getenv('BUILD_DOCS') != 'yes'
+    if not os.path.exists('docs/_build/html') and not skip_docs:
         kitten_exe = os.path.join(os.path.dirname(str(launcher)), 'kitten')
         if os.path.exists(kitten_exe):
             os.environ['KITTEN_EXE_FOR_DOCS'] = kitten_exe
