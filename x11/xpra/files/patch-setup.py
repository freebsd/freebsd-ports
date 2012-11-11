--- setup.py.orig	2012-11-08 10:32:55.726940413 -0500
+++ setup.py	2012-11-08 10:33:07.064940881 -0500
@@ -436,7 +436,7 @@
 #*******************************************************************************
 else:
     data_files += [
-                    ("share/man/man1", ["man/xpra.1", "man/xpra_launcher.1", "man/parti.1"]),
+                    ("man/man1", ["man/xpra.1", "man/xpra_launcher.1", "man/parti.1"]),
                     ("share/parti", ["README", "parti.README"]),
                     ("share/xpra", ["xpra.README", "COPYING"]),
                     ("share/wimpiggy", ["wimpiggy.README"]),
