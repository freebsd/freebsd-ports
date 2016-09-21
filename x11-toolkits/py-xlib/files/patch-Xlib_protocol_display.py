--- Xlib/protocol/display.py.orig	2016-08-10 13:52:51 UTC
+++ Xlib/protocol/display.py
@@ -562,7 +562,7 @@ class Display(object):
                 # We're the recieving thread, parse the data
                 if recieving:
                     try:
-                        bytes_recv = self.socket.recv(2048)
+                        bytes_recv = self.socket.recv(4096)
                     except socket.error as err:
                         self.close_internal('server: %s' % err[1])
                         raise self.socket_error
