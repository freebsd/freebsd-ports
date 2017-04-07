--- setup.py.orig	2017-04-02 13:48:04 UTC
+++ setup.py
@@ -1804,12 +1804,12 @@ if WIN32:
 else:
     #OSX and *nix:
     scripts += ["scripts/xpra", "scripts/xpra_launcher"]
-    add_data_files("share/man/man1",      ["man/xpra.1", "man/xpra_launcher.1"])
+    add_data_files("man/man1",            ["man/xpra.1", "man/xpra_launcher.1"])
     add_data_files("share/xpra",          ["README", "COPYING"])
     add_data_files("share/xpra/icons",    glob.glob("icons/*"))
     add_data_files("share/applications",  ["xdg/xpra_launcher.desktop", "xdg/xpra.desktop"])
     add_data_files("share/mime/packages", ["xdg/application-x-xpraconfig.xml"])
-    add_data_files("share/icons",         ["xdg/xpra.png"])
+    add_data_files("share/pixmaps",       ["xdg/xpra.png"])
     add_data_files("share/appdata",       ["xdg/xpra.appdata.xml"])
 
     #here, we override build and install so we can
@@ -1842,7 +1842,7 @@ else:
             if printing_ENABLED and os.name=="posix":
                 #install "/usr/lib/cups/backend" with 0700 permissions:
                 xpraforwarder_src = os.path.join("cups", "xpraforwarder")
-                cups_backend_dir = os.path.join(self.install_dir, "lib", "cups", "backend")
+                cups_backend_dir = os.path.join(self.install_dir, "libexec", "cups", "backend")
                 self.mkpath(cups_backend_dir)
                 xpraforwarder_dst = os.path.join(cups_backend_dir, "xpraforwarder")
                 shutil.copyfile(xpraforwarder_src, xpraforwarder_dst)
@@ -1894,7 +1894,7 @@ else:
         add_packages("xpra.platform.xposix")
         remove_packages("xpra.platform.win32", "xpra.platform.darwin")
         #not supported by all distros, but doesn't hurt to install it anyway:
-        add_data_files("/usr/lib/tmpfiles.d", ["tmpfiles.d/xpra.conf"])
+        #add_data_files("/usr/lib/tmpfiles.d", ["tmpfiles.d/xpra.conf"])
 
     #gentoo does weird things, calls --no-compile with build *and* install
     #then expects to find the cython modules!? ie:
