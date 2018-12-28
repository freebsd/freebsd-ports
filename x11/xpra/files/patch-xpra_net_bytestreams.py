--- xpra/net/bytestreams.py.orig	2018-12-28 00:32:28 UTC
+++ xpra/net/bytestreams.py
@@ -378,7 +378,7 @@ class SocketConnection(Connection):
                 fd = 0
             if fd:
                 info["fileno"] = fd
-            from xpra.platform.netdev_query import get_interface_info
+            #from xpra.platform.netdev_query import get_interface_info
             #ie: self.local = ("192.168.1.7", "14500")
             if self.local and len(self.local)==2:
                 from xpra.net.net_util import get_interface
