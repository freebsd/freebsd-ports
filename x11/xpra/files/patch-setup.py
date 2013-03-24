--- setup.py.orig	2013-02-21 15:27:40.000000000 +0000
+++ setup.py	2013-03-24 18:51:02.000000000 +0000
@@ -568,7 +568,7 @@
     scripts = ["scripts/xpra", "scripts/xpra_launcher"]
     man_pages = ["man/xpra.1", "man/xpra_launcher.1"]
     data_files += [
-                    ("share/man/man1", man_pages),
+                    ("man/man1", man_pages),
                     ("share/xpra", ["xpra.README", "COPYING"]),
                     ("share/wimpiggy", ["wimpiggy.README"]),
                     ("share/xpra/icons", glob.glob("icons/*")),
