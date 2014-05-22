--- setup.py.orig	2014-05-03 11:17:34.000000000 +0200
+++ setup.py	2014-05-10 23:32:05.126238947 +0200
@@ -960,7 +960,7 @@
     #OSX and *nix:
     scripts += ["scripts/xpra", "scripts/xpra_launcher"]
     data_files += [
-                    ("share/man/man1",      ["man/xpra.1", "man/xpra_launcher.1"]),
+                    ("man/man1",      ["man/xpra.1", "man/xpra_launcher.1"]),
                     ("share/xpra",          ["README", "COPYING"]),
                     ("share/xpra/icons",    glob.glob("icons/*")),
                     ("share/applications",  ["xdg/xpra_launcher.desktop", "xdg/xpra.desktop"]),
@@ -1003,7 +1003,11 @@
             if not use_Xdummy_wrapper and "scripts/xpra_Xdummy" in scripts:
                 #if we're not using the wrapper, don't install it
                 scripts.remove("scripts/xpra_Xdummy")
-            etc_files.append(xorg_conf)
+            ## FreeBSD ports: we want to install this as xpra.conf.sample
+            ## Prevent it here, handle in post-install target
+            #etc_files.append(xorg_conf)
+            ## FreeBSD ports: override etc_prefix
+            etc_prefix='etc/xpra'
         data_files.append((etc_prefix, etc_files))
 
     if OSX and "py2app" in sys.argv:
