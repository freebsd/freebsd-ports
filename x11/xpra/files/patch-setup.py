--- setup.py.orig	2017-02-06 09:47:42 UTC
+++ setup.py
@@ -218,7 +218,7 @@ else:
     nvenc7_ENABLED          = DEFAULT and pkg_config_ok("--exists", "nvenc7")
 
 memoryview_ENABLED      = sys.version>='2.7'
-csc_opencl_ENABLED      = DEFAULT and pkg_config_ok("--exists", "OpenCL") and check_pyopencl_AMD()
+csc_opencl_ENABLED      = DEFAULT and pkg_config_ok("--exists", "OpenCL")
 csc_libyuv_ENABLED      = DEFAULT and memoryview_ENABLED and pkg_config_ok("--exists", "libyuv", fallback=WIN32)
 
 #Cython / gcc / packaging build options:
@@ -1839,12 +1839,12 @@ if WIN32:
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
@@ -1877,7 +1877,7 @@ else:
             if printing_ENABLED and os.name=="posix":
                 #install "/usr/lib/cups/backend" with 0700 permissions:
                 xpraforwarder_src = os.path.join("cups", "xpraforwarder")
-                cups_backend_dir = os.path.join(self.install_dir, "lib", "cups", "backend")
+                cups_backend_dir = os.path.join(self.install_dir, "libexec", "cups", "backend")
                 self.mkpath(cups_backend_dir)
                 xpraforwarder_dst = os.path.join(cups_backend_dir, "xpraforwarder")
                 shutil.copyfile(xpraforwarder_src, xpraforwarder_dst)
@@ -1895,7 +1895,8 @@ else:
                 #install xorg.conf, cuda.conf and nvenc.keys:
                 etc_xpra = os.path.join(etc_prefix, "etc", "xpra")
                 self.mkpath(etc_xpra)
-                for x in ("xorg.conf", "cuda.conf", "nvenc.keys"):
+                etc_files = ["xorg.conf", "cuda.conf", "nvenc.keys"] if nvenc7_ENABLED else ["xorg.conf"]
+                for x in etc_files:
                     shutil.copyfile("etc/xpra/%s" % x, os.path.join(etc_xpra, x))
 
             if pam_ENABLED:
@@ -1928,7 +1929,7 @@ else:
         add_packages("xpra.platform.xposix")
         remove_packages("xpra.platform.win32", "xpra.platform.darwin")
         #not supported by all distros, but doesn't hurt to install it anyway:
-        add_data_files("lib/tmpfiles.d", ["tmpfiles.d/xpra.conf"])
+        #add_data_files("lib/tmpfiles.d", ["tmpfiles.d/xpra.conf"])
 
     #gentoo does weird things, calls --no-compile with build *and* install
     #then expects to find the cython modules!? ie:
@@ -2353,7 +2354,10 @@ if enc_x265_ENABLED:
 
 toggle_packages(enc_xvid_ENABLED, "xpra.codecs.enc_xvid")
 if enc_xvid_ENABLED:
-    xvid_pkgconfig = pkgconfig("xvid")
+    xvid_pkgconfig = pkgconfig(optimize=3)
+    add_to_keywords(xvid_pkgconfig, 'libraries', "xvidcore")
+    add_to_keywords(xvid_pkgconfig, 'library_dirs', "%%LOCALBASE%%/lib")
+    add_to_keywords(xvid_pkgconfig, 'include_dirs', "%%LOCALBASE%%/include")
     cython_add(Extension("xpra.codecs.enc_xvid.encoder",
                 ["xpra/codecs/enc_xvid/encoder.pyx", buffers_c],
                 **xvid_pkgconfig))
