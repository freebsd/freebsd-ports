--- setup.py.orig	2008-02-20 00:05:58.000000000 +0000
+++ setup.py	2008-04-06 14:03:24.000000000 +0100
@@ -2,23 +2,19 @@
 
 from distutils.core import setup
 from distutils.command.install_data import install_data
+from distutils.command.build import build
 from distutils.dep_util import newer
 from distutils.log import info
 import glob
 import os
 import sys
 
-class InstallData(install_data):
-  def run (self):
-    self.data_files.extend (self._compile_po_files ())
-    install_data.run (self)
-
-  def _compile_po_files (self):
-    data_files = []
-
+class BuildData(build):
+  def run(self):
+    build.run(self)
     # Don't install language files on win32
-    if sys.platform == 'win32':
-      return data_files
+    if sys.platform == 'win32' or os.environ.has_key("WITHOUT_NLS"):
+      return
 
     PO_DIR = 'po'
     for po in glob.glob (os.path.join (PO_DIR,'*.po')):
@@ -37,8 +33,25 @@
         if os.system(cmd) != 0:
           raise SystemExit('Error while running msgfmt')
 
-        dest = os.path.dirname(os.path.join('share', 'locale', lang, 'LC_MESSAGES', 'terminator.mo'))
-        data_files.append((dest, [mo]))
+class InstallData(install_data):
+  def run (self):
+    self.data_files.extend (self._compile_po_files ())
+    install_data.run (self)
+
+  def _compile_po_files (self):
+    data_files = []
+
+    # Don't install language files on win32
+    if sys.platform == 'win32' or os.environ.has_key("WITHOUT_NLS"):
+      return data_files
+
+    PO_DIR = 'po'
+    for po in glob.glob (os.path.join (PO_DIR,'*.po')):
+      lang = os.path.basename(po[:-3])
+      mo = os.path.join('build', 'mo', lang, 'terminator.mo')
+
+      dest = os.path.dirname(os.path.join('share', 'locale', lang, 'LC_MESSAGES', 'terminator.mo'))
+      data_files.append((dest, [mo]))
 
     return data_files
 
@@ -53,7 +66,7 @@
       scripts=['terminator'],
       data_files=[
                   ('share/applications', ['data/terminator.desktop']),
-                  ('share/man/man1', ['doc/terminator.1']),
+                  ('man/man1', ['doc/terminator.1']),
                   ('share/pixmaps', ['data/icons/48x48/apps/terminator.png']),
                   ('share/icons/hicolor/scalable/apps', glob.glob('data/icons/scalable/apps/*.svg')),
                   ('share/icons/hicolor/16x16/apps', glob.glob('data/icons/16x16/apps/*.png')),
@@ -61,6 +74,6 @@
                   ('share/icons/hicolor/24x24/apps', glob.glob('data/icons/24x24/apps/*.png')),
                   ('share/icons/hicolor/48x48/apps', glob.glob('data/icons/48x48/apps/*.png')),
                  ],
-      cmdclass={'install_data': InstallData}
+      cmdclass={'build': BuildData, 'install_data': InstallData}
      )
 
