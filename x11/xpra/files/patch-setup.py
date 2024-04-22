--- setup.py.orig	2024-02-06 07:54:06 UTC
+++ setup.py
@@ -1762,7 +1762,7 @@ else:
     if data_ENABLED:
         man_path = "share/man"
         icons_dir = "icons"
-        if OPENBSD or FREEBSD:
+        if OPENBSD:
             man_path = "man"
         if OPENBSD or FREEBSD or is_openSUSE():
             icons_dir = "pixmaps"
