- setuptools-lint isn't really needed during build

--- setup.py.orig	2022-01-01 19:56:27 UTC
+++ setup.py
@@ -23,8 +23,9 @@ SETUP_PACKAGES = [
 
 #: Additional requirements used during setup
 SETUP_PACKAGES = [
-    'setuptools-lint >=0.5',
-    'sphinx >=1.3.1']
+    #'setuptools-lint >=0.5',
+    #'sphinx >=1.3.1']
+    ]
 
 #: Packages requires for different environments
 EXTRA_PACKAGES = {
