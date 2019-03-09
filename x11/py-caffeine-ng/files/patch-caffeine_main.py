--- caffeine/main.py.orig	2018-05-17 01:08:07 UTC
+++ caffeine/main.py
@@ -412,8 +412,8 @@ def main():
     GObject.threads_init()
 
     # register the process id as 'caffeine'
-    libc = ctypes.cdll.LoadLibrary('libc.so.6')
-    libc.prctl(15, 'caffeine', 0, 0, 0)
+    # libc = ctypes.cdll.LoadLibrary('libc.so.6')
+    # libc.prctl(15, 'caffeine', 0, 0, 0)
 
     arguments = docopt(__doc__, version=__version__)
 
