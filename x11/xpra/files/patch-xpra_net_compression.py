--- xpra/net/compression.py.orig	2015-07-27 14:25:13 UTC
+++ xpra/net/compression.py
@@ -23,7 +23,9 @@ try:
         return level | LZ4_FLAG, LZ4_compress(packet)
     #try to figure out the version number:
     if hasattr(lz4, "VERSION"):
-        lz4_version = str(lz4.VERSION)
+        lz4_version = lz4.VERSION
+        if hasattr(lz4, "LZ4_VERSION"):
+            lz4_version.append(lz4.LZ4_VERSION)
     elif hasattr(lz4, "__file__"):
         #hack it..
         import os.path
@@ -44,10 +46,8 @@ try:
                 #we want at least two numbers first:
                 if len(tmpv)>=2:
                     #ie: (0, 7, 0)
-                    lz4_version = ".".join(tmpv)
-    assert lz4_version>="0.7", "versions older than 0.7.0 are vulnerable and should not be used, see CVE-2014-4715"
-    if hasattr(lz4, "LZ4_VERSION"):
-        lz4_version += "."+str(lz4.LZ4_VERSION)
+                    lz4_version = tuple(tmpv)
+                    assert lz4_version>=(0, 7), "versions older than 0.7.0 are vulnerable and should not be used, see CVE-2014-4715"
 except Exception as e:
     log("lz4 not found: %s", e)
     LZ4_uncompress = None
