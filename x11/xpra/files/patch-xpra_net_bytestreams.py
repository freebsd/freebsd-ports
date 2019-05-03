--- xpra/net/bytestreams.py.orig	2019-03-19 15:05:11 UTC
+++ xpra/net/bytestreams.py
@@ -410,7 +410,7 @@ class SocketConnection(Connection):
                 fd = 0
             if fd:
                 info["fileno"] = fd
-            from xpra.platform.netdev_query import get_interface_info
+            #from xpra.platform.netdev_query import get_interface_info
             #ie: self.local = ("192.168.1.7", "14500")
             if self.local and len(self.local)==2:
                 from xpra.net.net_util import get_interface
