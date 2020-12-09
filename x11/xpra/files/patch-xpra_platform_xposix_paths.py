--- xpra/platform/xposix/paths.py.orig	2020-11-18 03:31:17 UTC
+++ xpra/platform/xposix/paths.py
@@ -146,6 +146,7 @@ def do_get_socket_dirs():
         SOCKET_DIRS.append("/run/xpra")
     elif os.path.exists("/var/run"):
         SOCKET_DIRS.append("/var/run/xpra")
+    SOCKET_DIRS.append("~/.xpra")
     return SOCKET_DIRS
 
 def do_get_default_log_dirs():
