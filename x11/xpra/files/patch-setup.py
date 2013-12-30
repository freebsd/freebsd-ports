--- ./setup.py.orig	2013-12-19 09:14:12.000000000 +0000
+++ ./setup.py	2013-12-21 21:13:18.689932655 +0000
@@ -862,7 +862,7 @@
     scripts = ["scripts/xpra", "scripts/xpra_launcher"]
     man_pages = ["man/xpra.1", "man/xpra_launcher.1"]
     data_files += [
-                    ("share/man/man1", man_pages),
+                    ("man/man1", man_pages),
                     ("share/xpra", ["README", "COPYING"]),
                     ("share/xpra/icons", glob.glob("icons/*")),
                     ("share/applications", ["xdg/xpra_launcher.desktop", "xdg/xpra.desktop"]),
@@ -910,7 +910,11 @@
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
     setup_options["scripts"] = scripts
 
