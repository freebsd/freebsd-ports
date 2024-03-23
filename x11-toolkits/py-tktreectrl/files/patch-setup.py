--- setup.py.orig	2013-05-06 09:00:53 UTC
+++ setup.py
@@ -1,9 +1,9 @@ from distutils.core import setup
 from distutils.core import setup
 
-version = '2.0'
+version = '%%PORTVERSION%%'
 
 setup(
-    name="TkinterTreectrl",
+    name="tktreectrl",
     version=version,
     description="Tkinter wrapper for TkTreectrl",
     author="Michael Lange",
