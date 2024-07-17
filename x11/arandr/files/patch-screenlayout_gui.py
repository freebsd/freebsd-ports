--- screenlayout/gui.py.orig	2024-06-06 09:08:21 UTC
+++ screenlayout/gui.py
@@ -45,7 +45,7 @@
 
     A first argument called 'self' is passed through.
     """
-    argnames = inspect.getargspec(function)[0]
+    argnames = inspect.getfullargspec(function)[0]
     if argnames[0] == 'self':
         has_self = True
         argnames.pop(0)
