--- setup.py.orig	2024-11-05 05:01:05 UTC
+++ setup.py
@@ -18,7 +18,7 @@ from distutils.command.build        import build as or
 from setuptools.command.install     import install as orig_install
 from setuptools.command.bdist_egg   import bdist_egg as orig_bdist_egg
 from setuptools.command.sdist       import sdist as orig_sdist
-from setuptools.command.bdist_wheel import bdist_wheel as orig_bdist_wheel
+from wheel.bdist_wheel import bdist_wheel as orig_bdist_wheel

 from buildtools.config import Config, msg, opj, runcmd, canGetSOName, getSOName
 import buildtools.version as version
