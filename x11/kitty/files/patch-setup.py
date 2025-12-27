--- setup.py	2025-12-16 12:38:37 UTC
+++ setup.py
@@ -1489,12 +1489,17 @@ def create_linux_bundle_gunk(ddir: str, args: Options)
     in_src_launcher = base / (f'{libdir_name}/kitty/kitty/launcher/kitty')
     launcher = base / 'bin/kitty'
     skip_docs = False
+    build_docs = os.getenv('BUILD_DOCS') == 'yes'
+    build_manpages = os.getenv('BUILD_MANPAGES') == 'yes'
     if not os.path.exists('docs/_build/html'):
         kitten_exe = os.path.join(os.path.dirname(str(launcher)), 'kitten')
         if os.path.exists(kitten_exe):
             os.environ['KITTEN_EXE_FOR_DOCS'] = kitten_exe
             make = 'gmake' if is_freebsd else 'make'
-            run_tool([make, 'docs'])
+            if build_docs:
+                run_tool([make, 'docs'])
+            if build_manpages:
+                run_tool([make, 'man'])
         else:
             if args.skip_building_kitten:
                 skip_docs = True
@@ -1504,8 +1509,10 @@ def create_linux_bundle_gunk(ddir: str, args: Options)
             else:
                 raise SystemExit(f'kitten binary not found at: {kitten_exe}')
     if not skip_docs:
-        copy_man_pages(ddir)
-        copy_html_docs(ddir)
+        if build_manpages:
+            copy_man_pages(ddir)
+        if build_docs:
+            copy_html_docs(ddir)
     for (icdir, ext) in {'256x256': 'png', 'scalable': 'svg'}.items():
         icdir = os.path.join(ddir, 'share', 'icons', 'hicolor', icdir, 'apps')
         safe_makedirs(icdir)
