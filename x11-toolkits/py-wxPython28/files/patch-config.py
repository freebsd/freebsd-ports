--- config.py.orig	2013-12-13 11:26:53.752427019 -0200
+++ config.py	2013-12-13 11:28:04.575423576 -0200
@@ -38,7 +38,7 @@
 from distutils.dep_util  import newer
 from distutils.spawn     import spawn
 
-import distutils.command.install
+import setuptools.command.install
 import distutils.command.install_data
 import distutils.command.install_headers
 import distutils.command.clean
@@ -480,7 +480,7 @@
 # is used in our package build.  If we detect that the current
 # distutils does not have it then make sure that it is removed from
 # the command-line options, otherwise the build will fail.
-for item in distutils.command.install.install.user_options:
+for item in setuptools.command.install.install.user_options:
     if item[0] == 'install-layout=':
         break
 else:
@@ -491,12 +491,12 @@
 
 
 
-class wx_install(distutils.command.install.install):
+class wx_install(setuptools.command.install.install):
     """
     Turns off install_path_file
     """
     def initialize_options(self):
-        distutils.command.install.install.initialize_options(self)
+        setuptools.command.install.install.initialize_options(self)
         self.install_path_file = 0
 
 
