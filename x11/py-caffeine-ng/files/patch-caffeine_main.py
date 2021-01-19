--- caffeine/main.py.orig	2021-01-01 14:03:23 UTC
+++ caffeine/main.py
@@ -30,7 +30,7 @@ Options:
   -p --preferences          Start with the Preferences dialog open.
 """
 # TODO: add a -v --verbosity flag.
-import ctypes
+# import ctypes
 import logging
 import os
 import signal
@@ -429,8 +429,8 @@ def main():
     GObject.threads_init()
 
     # register the process id as 'caffeine'
-    libc = ctypes.cdll.LoadLibrary("libc.so.6")
-    libc.prctl(15, "caffeine", 0, 0, 0)
+    # libc = ctypes.cdll.LoadLibrary("libc.so.6")
+    # libc.prctl(15, "caffeine", 0, 0, 0)
 
     arguments = docopt(__doc__, version=__version__)
 
