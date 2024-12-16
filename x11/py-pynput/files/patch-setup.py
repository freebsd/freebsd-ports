- setuptools-lint isn't really needed during build

--- setup.py.orig	2024-05-10 13:18:06 UTC
+++ setup.py
@@ -23,8 +23,6 @@ SETUP_PACKAGES = [
 
 #: Additional requirements used during setup
 SETUP_PACKAGES = [
-    'setuptools-lint >=0.5',
-    'sphinx >=1.3.1',
     'twine >=4.0']
 
 #: Packages requires for different environments
