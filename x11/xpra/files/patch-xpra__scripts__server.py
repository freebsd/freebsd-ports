--- ./xpra/scripts/server.py.orig	2013-08-21 11:46:11.000000000 +0000
+++ ./xpra/scripts/server.py	2013-12-21 21:11:14.279941696 +0000
@@ -9,6 +9,7 @@
 #  http://lists.partiwm.org/pipermail/parti-discuss/2008-September/000042.html
 # (also do not import anything that imports gtk)
 import gobject
+import glib
 import subprocess
 import sys
 import os.path
@@ -451,7 +452,7 @@
         # Now we can safely load gtk and connect:
         assert "gtk" not in sys.modules
         import gtk.gdk          #@Reimport
-        gtk.gdk.threads_init()
+        glib.threads_init()
         display = gtk.gdk.Display(display_name)
         manager = gtk.gdk.display_manager_get()
         default_display = manager.get_default_display()
