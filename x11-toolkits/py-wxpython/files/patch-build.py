--- build.py.orig	2025-10-29 00:38:50 UTC
+++ build.py
@@ -423,7 +423,7 @@ def makeOptionParser():
         ("mac_framework",  (False, "Build wxWidgets as a Mac framework.")),
         ("mac_arch",       ("",    "Comma separated list of architectures to build on Mac")),
 
-        ("use_syswx",      (False, "Try to use an installed wx rather than building the "
+        ("use_syswx",      (True,  "Try to use an installed wx rather than building the "
                                    "one in this source tree.  The wx-config in {prefix}/bin "
                                    "or the first found on the PATH determines which wx is "
                                    "used.  Implies --no_magic.")),
