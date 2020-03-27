--- setup.py.orig	2020-03-13 16:51:18 UTC
+++ setup.py
@@ -1491,7 +1491,7 @@ else:
         libexec = "libexec"
     else:
         libexec = "lib"
-    if LINUX:
+    if LINUX or FREEBSD:
         if scripts_ENABLED:
             scripts += ["scripts/xpra_udev_product_version", "scripts/xpra_signal_listener"]
         libexec_scripts = []
@@ -1508,7 +1508,7 @@ else:
         add_data_files("%s/man1" % man_path,  ["man/xpra.1", "man/xpra_launcher.1"])
         add_data_files("share/applications",  glob.glob("xdg/*.desktop"))
         add_data_files("share/mime/packages", ["xdg/application-x-xpraconfig.xml"])
-        add_data_files("share/icons",         ["xdg/xpra.png", "xdg/xpra-mdns.png", "xdg/xpra-shadow.png"])
+        add_data_files("share/pixmaps",         ["xdg/xpra.png", "xdg/xpra-mdns.png", "xdg/xpra-shadow.png"])
         add_data_files("share/metainfo",      ["xdg/xpra.appdata.xml"])
 
     #here, we override build and install so we can
@@ -1633,8 +1633,8 @@ else:
         remove_packages("xpra.platform.win32", "xpra.platform.darwin")
         if data_ENABLED:
             #not supported by all distros, but doesn't hurt to install them anyway:
-            for x in ("tmpfiles.d", "sysusers.d"):
-                add_data_files("lib/%s" % x, ["%s/xpra.conf" % x])
+#            for x in ("tmpfiles.d", "sysusers.d"):
+#                add_data_files("lib/%s" % x, ["%s/xpra.conf" % x])
             if uinput_ENABLED:
                 add_data_files("lib/udev/rules.d/", ["udev/rules.d/71-xpra-virtual-pointer.rules"])
 
