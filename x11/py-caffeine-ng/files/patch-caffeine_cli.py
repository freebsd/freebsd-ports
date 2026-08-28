--- caffeine/cli.py.orig	2026-04-13 21:30:19 UTC
+++ caffeine/cli.py
@@ -1,4 +1,4 @@
-import ctypes
+# import ctypes
 import logging
 import signal
 
@@ -20,8 +20,8 @@ def cli(ctx: click.Context, verbose: bool) -> None:
     signal.signal(signal.SIGINT, signal.SIG_DFL)
 
     # register the process id as 'caffeine'
-    libc = ctypes.cdll.LoadLibrary("libc.so.6")
-    libc.prctl(15, "caffeine", 0, 0, 0)
+    # libc = ctypes.cdll.LoadLibrary("libc.so.6")
+    # libc.prctl(15, "caffeine", 0, 0, 0)
 
     if verbose:
         logging.basicConfig(level=logging.DEBUG)
