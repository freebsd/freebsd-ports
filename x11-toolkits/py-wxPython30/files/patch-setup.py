--- setup.py.orig	2014-06-23 12:08:27.268192923 -0300
+++ setup.py	2014-06-23 12:07:08.925198614 -0300
 BUILD_OPTIONS = { 'build_base' : BUILD_BASE }
@@ -1011,7 +1006,7 @@
     if not PREP_ONLY:
 
         if not EGGing:
-            if INSTALL_MULTIVERSION:
+            if False:
                 setup(name             = 'wxPython-common',
                       version          = VERSION,
                       description      = DESCRIPTION,
