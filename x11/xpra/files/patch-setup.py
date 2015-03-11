--- setup.py.orig	2015-02-17 19:57:07.000000000 -0500
+++ setup.py	2015-03-11 14:49:57.342199000 -0400
@@ -1416,7 +1416,7 @@
 else:
     #OSX and *nix:
     scripts += ["scripts/xpra", "scripts/xpra_launcher"]
-    add_data_files("share/man/man1",      ["man/xpra.1", "man/xpra_launcher.1"])
+    add_data_files("man/man1",      ["man/xpra.1", "man/xpra_launcher.1"])
     add_data_files("share/xpra",          ["README", "COPYING"])
     add_data_files("share/xpra/icons",    glob.glob("icons/*"))
     add_data_files("share/applications",  ["xdg/xpra_launcher.desktop", "xdg/xpra.desktop"])
