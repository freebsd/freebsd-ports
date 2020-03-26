--- setup.py.orig	2020-02-07 11:19:08 UTC
+++ setup.py
@@ -165,7 +165,7 @@ html5_brotli_ENABLED = DEFAULT
 minify_ENABLED = html5_ENABLED
 pam_ENABLED = DEFAULT and (server_ENABLED or proxy_ENABLED) and POSIX and not OSX and (os.path.exists("/usr/include/pam/pam_misc.h") or os.path.exists("/usr/include/security/pam_misc.h"))
 
-xdg_open_ENABLED        = LINUX and DEFAULT
+xdg_open_ENABLED        = (LINUX or FREEBSD) and DEFAULT
 netdev_ENABLED          = LINUX and DEFAULT
 vsock_ENABLED           = LINUX and os.path.exists("/usr/include/linux/vm_sockets.h")
 bencode_ENABLED         = DEFAULT
@@ -1481,11 +1481,11 @@ if WIN32:
 #*******************************************************************************
 else:
     #OSX and *nix:
-    if LINUX:
+    if LINUX or FREEBSD:
         if scripts_ENABLED:
             scripts += ["scripts/xpra_udev_product_version", "scripts/xpra_signal_listener"]
         libexec_scripts = []
-        if is_Fedora() or is_CentOS() or is_RedHat():
+        if is_Fedora() or is_CentOS() or is_RedHat() or FREEBSD:
             libexec = "libexec"
         else:
             libexec = "lib"
@@ -1497,12 +1497,12 @@ else:
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
+        add_data_files("share/pixmaps",         ["xdg/xpra.png", "xdg/xpra-mdns.png", "xdg/xpra-shadow.png"])
         add_data_files("share/metainfo",      ["xdg/xpra.appdata.xml"])
 
     #here, we override build and install so we can
@@ -1551,7 +1551,7 @@ else:
 
             if printing_ENABLED and POSIX:
                 #install "/usr/lib/cups/backend" with 0700 permissions:
-                copytodir("cups/xpraforwarder", "lib/cups/backend", chmod=0o700)
+                copytodir("cups/xpraforwarder", "libexec/cups/backend", chmod=0o700)
 
             if x11_ENABLED:
                 #install xpra_Xdummy if we need it:
@@ -1624,8 +1624,8 @@ else:
         remove_packages("xpra.platform.win32", "xpra.platform.darwin")
         if data_ENABLED:
             #not supported by all distros, but doesn't hurt to install them anyway:
-            for x in ("tmpfiles.d", "sysusers.d"):
-                add_data_files("lib/%s" % x, ["%s/xpra.conf" % x])
+#            for x in ("tmpfiles.d", "sysusers.d"):
+#                add_data_files("lib/%s" % x, ["%s/xpra.conf" % x])
             if uinput_ENABLED:
                 add_data_files("lib/udev/rules.d/", ["udev/rules.d/71-xpra-virtual-pointer.rules"])
 
