--- setup.py.orig	2015-09-10 14:42:44 UTC
+++ setup.py
@@ -147,7 +147,7 @@ nvenc4_ENABLED          = pkg_config_ok(
 nvenc5_ENABLED          = pkg_config_ok("--exists", "nvenc5")
 #elif os.path.exists("C:\\nvenc_3.0_windows_sdk")
 #...
-csc_opencl_ENABLED      = pkg_config_ok("--exists", "OpenCL") and check_pyopencl_AMD()
+csc_opencl_ENABLED      = pkg_config_ok("--exists", "OpenCL")
 memoryview_ENABLED      = PYTHON3
 
 warn_ENABLED            = True
@@ -1560,12 +1560,12 @@ if WIN32:
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
     html5_dir = "share/xpra/www"
 
@@ -1688,7 +1688,7 @@ if html5_ENABLED:
 
 if printing_ENABLED and os.name=="posix":
     #"/usr/lib/cups/backend":
-    cups_backend_dir = os.path.join(sys.prefix, "lib", "cups", "backend")
+    cups_backend_dir = os.path.join(sys.prefix, "libexec", "cups", "backend")
     add_data_files(cups_backend_dir, ["cups/xpraforwarder"])
 
 
