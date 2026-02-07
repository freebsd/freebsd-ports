remove after setuptools update past 70.1

--- setup.py.orig	2025-10-29 00:38:50 UTC
+++ setup.py
@@ -18,7 +18,10 @@ from setuptools.command.sdist       import sdist as or
 from setuptools.command.install     import install as orig_install
 from setuptools.command.bdist_egg   import bdist_egg as orig_bdist_egg
 from setuptools.command.sdist       import sdist as orig_sdist
-from setuptools.command.bdist_wheel import bdist_wheel as orig_bdist_wheel
+try:
+    from setuptools.command.bdist_wheel import bdist_wheel as orig_bdist_wheel
+except ImportError:
+    from wheel.bdist_wheel import bdist_wheel as orig_bdist_wheel
 
 # Alter the path so that buildtools can be imported from the current directory.
 sys.path.insert(0, os.path.dirname(__file__))
