- setuptools-lint isn't really needed during build

--- setup.py.orig	2023-01-31 20:21:18 UTC
+++ setup.py
@@ -23,7 +23,7 @@ RUNTIME_PACKAGES = [
 
 #: Additional requirements used during setup
 SETUP_PACKAGES = [
-    'setuptools-lint >=0.5',
+    #'setuptools-lint >=0.5',
     'sphinx >=1.3.1']
 
 #: Packages requires for different environments
