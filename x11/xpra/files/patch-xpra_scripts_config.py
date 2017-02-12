# Chaneset 15036 in xpra
# Timestamp: 02/11/17 05:03:04
# Author: Antoine Martin
# Message: make sure we call makedirs on the expanded path
#
--- xpra/scripts/config.py.orig	2016-12-30 04:31:45 UTC
+++ xpra/scripts/config.py
@@ -401,8 +401,8 @@ def may_create_user_config(xpra_conf_fil
                 ad = os.path.expanduser(d)
                 conf_file = os.path.join(ad, xpra_conf_filename)
                 try:
-                    if not os.path.exists(d):
-                        os.makedirs(d, int('700', 8))
+                    if not os.path.exists(ad):
+                        os.makedirs(ad, int('700', 8))
                     with open(conf_file, 'wb') as f:
                         f.write("# xpra user configuration file\n")
                         f.write("# place your custom settings in this file\n")
