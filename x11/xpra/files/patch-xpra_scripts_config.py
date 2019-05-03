--- xpra/scripts/config.py.orig	2019-04-16 04:57:10 UTC
+++ xpra/scripts/config.py
@@ -126,7 +126,6 @@ def detect_xvfb_command(conf_dir="/etc/xpra/", bin_dir
     if OSX:
         return get_Xvfb_command()
     if sys.platform.find("bsd")>=0 and Xdummy_ENABLED is None:
-        warn("Warning: sorry, no support for Xdummy on %s" % sys.platform)
         return get_Xvfb_command()
 
     xorg_bin = get_xorg_bin()
