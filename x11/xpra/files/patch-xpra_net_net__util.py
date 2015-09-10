--- xpra/net/net_util.py.orig	2015-04-30 14:59:58 UTC
+++ xpra/net/net_util.py
@@ -127,7 +127,7 @@ if not sys.platform.startswith("win"):
 	elif sys.platform.startswith("sunos"):
 		library = "libsocket.so.1"
 	elif sys.platform.startswith("freebsd"):
-		library = "/usr/lib/libc.so"
+		library = "/lib/libc.so.7"
 	elif sys.platform.startswith("openbsd"):
 		library = "libc.so"
 	try:
