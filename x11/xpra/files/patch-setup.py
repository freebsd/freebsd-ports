--- setup.py.orig	2018-10-14 16:59:57 UTC
+++ setup.py
@@ -1508,12 +1508,12 @@ else:
         if libexec_scripts:
             add_data_files("%s/xpra/" % libexec, libexec_scripts)
     man_path = "share/man"
-    if OPENBSD:
+    if OPENBSD or FREEBSD:
         man_path = "man"
     add_data_files("%s/man1" % man_path,  ["man/xpra.1", "man/xpra_launcher.1", "man/xpra_browser.1"])
     add_data_files("share/applications",  ["xdg/xpra-shadow.desktop", "xdg/xpra-launcher.desktop", "xdg/xpra-browser.desktop", "xdg/xpra.desktop"])
     add_data_files("share/mime/packages", ["xdg/application-x-xpraconfig.xml"])
-    add_data_files("share/icons",         ["xdg/xpra.png", "xdg/xpra-mdns.png", "xdg/xpra-shadow.png"])
+    add_data_files("share/pixmaps",       ["xdg/xpra.png", "xdg/xpra-mdns.png", "xdg/xpra-shadow.png"])
     add_data_files("share/appdata",       ["xdg/xpra.appdata.xml"])
 
     #here, we override build and install so we can
@@ -1562,7 +1562,7 @@ else:
 
             if printing_ENABLED and POSIX:
                 #install "/usr/lib/cups/backend" with 0700 permissions:
-                copytodir("cups/xpraforwarder", "lib/cups/backend", chmod=0o700)
+                copytodir("cups/xpraforwarder", "libexec/cups/backend", chmod=0o700)
 
             if x11_ENABLED:
                 #install xpra_Xdummy if we need it:
@@ -1634,8 +1634,8 @@ else:
         add_packages("xpra.platform.xposix")
         remove_packages("xpra.platform.win32", "xpra.platform.darwin")
         #not supported by all distros, but doesn't hurt to install them anyway:
-        for x in ("tmpfiles.d", "sysusers.d"):
-            add_data_files("lib/%s" % x, ["%s/xpra.conf" % x])
+#        for x in ("tmpfiles.d", "sysusers.d"):
+#            add_data_files("lib/%s" % x, ["%s/xpra.conf" % x])
         if uinput_ENABLED:
             add_data_files("lib/udev/rules.d/", ["udev/rules.d/71-xpra-virtual-pointer.rules"])
 
