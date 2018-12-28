--- xpra/scripts/config.py.orig	2018-12-28 02:45:20 UTC
+++ xpra/scripts/config.py
@@ -123,7 +123,6 @@ def detect_xvfb_command(conf_dir="/etc/xpra/", bin_dir
     if OSX:
         return get_Xvfb_command()
     if sys.platform.find("bsd")>=0 and Xdummy_ENABLED is None:
-        warn("Warning: sorry, no support for Xdummy on %s" % sys.platform)
         return get_Xvfb_command()
 
     xorg_bin = get_xorg_bin()
