--- ./setup.py.orig	2013-12-20 21:07:29.448820756 +0000
+++ ./setup.py	2013-12-20 21:07:38.485819828 +0000
@@ -862,7 +862,7 @@
     scripts = ["scripts/xpra", "scripts/xpra_launcher"]
     man_pages = ["man/xpra.1", "man/xpra_launcher.1"]
     data_files += [
-                    ("share/man/man1", man_pages),
+                    ("man/man1", man_pages),
                     ("share/xpra", ["README", "COPYING"]),
                     ("share/xpra/icons", glob.glob("icons/*")),
                     ("share/applications", ["xdg/xpra_launcher.desktop", "xdg/xpra.desktop"]),
