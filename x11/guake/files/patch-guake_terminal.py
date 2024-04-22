--- guake/terminal.py.orig	2021-08-01 08:12:10 UTC
+++ guake/terminal.py
@@ -61,7 +61,7 @@ try:
     # be injected in current process, as: wall
     from atexit import register as at_exit_call
     from ctypes import cdll
-    libutempter = cdll.LoadLibrary('libutempter.so.0')
+    libutempter = cdll.LoadLibrary('libutempter.so')
     if libutempter is not None:
         # We absolutely need to remove the old tty from the utmp !!!
         at_exit_call(libutempter.utempter_remove_added_record)
