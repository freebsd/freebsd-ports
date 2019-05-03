--- setup.py.orig	2019-03-19 15:05:07 UTC
+++ setup.py
@@ -1551,12 +1551,12 @@ else:
             add_data_files("%s/xpra/" % libexec, libexec_scripts)
     if data_ENABLED:
         man_path = "share/man"
-        if OPENBSD:
+        if OPENBSD or FREEBSD:
             man_path = "man"
         add_data_files("%s/man1" % man_path,  ["man/xpra.1", "man/xpra_launcher.1"])
         add_data_files("share/applications",  glob.glob("xdg/*.desktop"))
         add_data_files("share/mime/packages", ["xdg/application-x-xpraconfig.xml"])
-        add_data_files("share/icons",         ["xdg/xpra.png", "xdg/xpra-mdns.png", "xdg/xpra-shadow.png"])
+        add_data_files("share/pixmaps",       ["xdg/xpra.png", "xdg/xpra-mdns.png", "xdg/xpra-shadow.png"])
         add_data_files("share/appdata",       ["xdg/xpra.appdata.xml"])
 
     #here, we override build and install so we can
@@ -1605,7 +1605,7 @@ else:
 
             if printing_ENABLED and POSIX:
                 #install "/usr/lib/cups/backend" with 0700 permissions:
-                copytodir("cups/xpraforwarder", "lib/cups/backend", chmod=0o700)
+                copytodir("cups/xpraforwarder", "libexec/cups/backend", chmod=0o700)
 
             if x11_ENABLED:
                 #install xpra_Xdummy if we need it:
@@ -1678,8 +1678,8 @@ else:
         remove_packages("xpra.platform.win32", "xpra.platform.darwin")
         if data_ENABLED:
             #not supported by all distros, but doesn't hurt to install them anyway:
-            for x in ("tmpfiles.d", "sysusers.d"):
-                add_data_files("lib/%s" % x, ["%s/xpra.conf" % x])
+#            for x in ("tmpfiles.d", "sysusers.d"):
+#                add_data_files("lib/%s" % x, ["%s/xpra.conf" % x])
             if uinput_ENABLED:
                 add_data_files("lib/udev/rules.d/", ["udev/rules.d/71-xpra-virtual-pointer.rules"])
 
