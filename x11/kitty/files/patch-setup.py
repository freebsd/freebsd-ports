--- setup.py.orig	1979-11-29 23:00:00 UTC
+++ setup.py
@@ -1432,12 +1432,16 @@ def create_linux_bundle_gunk(ddir: str, args: Options)
     in_src_launcher = base / (f'{libdir_name}/kitty/kitty/launcher/kitty')
     launcher = base / 'bin/kitty'
     skip_docs = False
+    build_docs = os.getenv('BUILD_DOCS') == 'yes'
     if not os.path.exists('docs/_build/html'):
         kitten_exe = os.path.join(os.path.dirname(str(launcher)), 'kitten')
         if os.path.exists(kitten_exe):
             os.environ['KITTEN_EXE_FOR_DOCS'] = kitten_exe
             make = 'gmake' if is_freebsd else 'make'
-            run_tool([make, 'docs'])
+            if build_docs:
+                run_tool([make, 'docs'])
+            else:
+                run_tool([make, 'man'])
         else:
             if args.skip_building_kitten:
                 skip_docs = True
@@ -1448,7 +1452,8 @@ def create_linux_bundle_gunk(ddir: str, args: Options)
                 raise SystemExit(f'kitten binary not found at: {kitten_exe}')
     if not skip_docs:
         copy_man_pages(ddir)
-        copy_html_docs(ddir)
+        if build_docs:
+            copy_html_docs(ddir)
     for (icdir, ext) in {'256x256': 'png', 'scalable': 'svg'}.items():
         icdir = os.path.join(ddir, 'share', 'icons', 'hicolor', icdir, 'apps')
         safe_makedirs(icdir)
