--- ulauncher/utils/display.py.orig	2021-02-07 15:10:13 UTC
+++ ulauncher/utils/display.py
@@ -1,4 +1,5 @@
-import logging
+import gi, logging
+gi.require_version('Gdk', '3.0')
 from gi.repository import Gdk, GdkX11
 
 logger = logging.getLogger(__name__)
