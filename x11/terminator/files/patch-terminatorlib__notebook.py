--- terminatorlib/notebook.py.orig	2020-04-19 03:13:43 UTC
+++ terminatorlib/notebook.py
@@ -77,17 +77,6 @@ class Notebook(Container, Gtk.Notebook):
 
     def create_layout(self, layout):
         """Apply layout configuration"""
-        def child_compare(a, b):
-            order_a = children[a]['order']
-            order_b = children[b]['order']
-
-            if (order_a == order_b):
-                return 0
-            if (order_a < order_b):
-                return -1
-            if (order_a > order_b):
-                return 1
-
         if 'children' not in layout:
             err('layout specifies no children: %s' % layout)
             return
@@ -100,7 +89,7 @@ class Notebook(Container, Gtk.Notebook):
 
         num = 0
         keys = list(children.keys())
-        keys.sort(child_compare)
+        keys.sort(key=lambda x: children[x]['order'])
 
         for child_key in keys:
             child = children[child_key]
