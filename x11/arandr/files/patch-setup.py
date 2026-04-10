--- setup.py.orig	2026-04-10 07:38:01 UTC
+++ setup.py
@@ -29,13 +29,15 @@ from distutils.log import info, warn
 from distutils.core import setup
 from distutils.dep_util import newer
 from distutils.log import info, warn
-from distutils.cmd import Command
+# from distutils.cmd import Command
 from distutils.command.build import build as _build
 from distutils.command.install_data import install_data as _install_data
 from distutils.command.install import install as _install
 from distutils.command.sdist import sdist as _sdist
 from distutils.dir_util import remove_tree
 from distutils.command.clean import clean as _clean
+
+from setuptools import Command
 
 
 PO_DIR = 'data/po'
