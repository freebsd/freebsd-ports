--- gladew.py.orig	Mon Dec 27 11:44:55 2004
+++ gladew.py	Mon Dec 27 11:44:39 2004
@@ -2,7 +2,11 @@
 pygtk.require('2.0')
 import gtk.glade
 import gobject
-import new, types
+import os, sys, new, types
+
+def find_datafile(filename):
+    prefix = os.path.split(os.path.dirname(sys.argv[0]))[0]
+    return os.path.join(prefix, 'share', 'xcurs', filename)
 
 class GladeWidget:
     #if we are doing instance counting, this holds the variable
@@ -13,7 +17,7 @@
 
         #initialize variables
         self.autoclose = autoclose
-        self.widgets = gtk.glade.XML(glade_file, widget_name)
+        self.widgets = gtk.glade.XML(find_datafile(glade_file), widget_name)
         callbacks = {}
 
         #find and store methods as bound callbacks
