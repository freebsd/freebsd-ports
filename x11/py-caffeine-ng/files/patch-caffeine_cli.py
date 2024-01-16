--- caffeine/cli.py.orig	2023-03-09 15:23:08 UTC
+++ caffeine/cli.py
@@ -1,4 +1,4 @@
-import ctypes
+# import ctypes
 import logging
 import signal
 
@@ -21,8 +21,8 @@ def cli(ctx, verbose):
     signal.signal(signal.SIGINT, signal.SIG_DFL)
 
     # register the process id as 'caffeine'
-    libc = ctypes.cdll.LoadLibrary("libc.so.6")
-    libc.prctl(15, "caffeine", 0, 0, 0)
+    # libc = ctypes.cdll.LoadLibrary("libc.so.6")
+    # libc.prctl(15, "caffeine", 0, 0, 0)
 
     if verbose:
         logging.basicConfig(level=logging.DEBUG)
