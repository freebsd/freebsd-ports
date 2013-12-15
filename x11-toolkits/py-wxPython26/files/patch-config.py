--- config.py.orig	2006-07-15 18:20:18.000000000 -0300
+++ config.py	2013-12-13 11:41:13.788425136 -0200
@@ -27,7 +27,7 @@
 from distutils.dep_util  import newer
 from distutils.spawn     import spawn
 
-import distutils.command.install
+import setuptools.command.install
 import distutils.command.install_data
 import distutils.command.install_headers
 import distutils.command.clean
@@ -448,12 +448,12 @@
 
 
 
-class wx_install(distutils.command.install.install):
+class wx_install(setuptools.command.install.install):
     """
     Turns off install_path_file
     """
     def initialize_options(self):
-        distutils.command.install.install.initialize_options(self)
+        setuptools.command.install.install.initialize_options(self)
         self.install_path_file = 0
         
 
