--- configure.py.orig	2019-11-02 18:58:12 UTC
+++ configure.py
@@ -690,7 +690,7 @@ class _TargetConfiguration:
         self.stubs_dir = ''
         self.distinfo = False
 
-        self.prot_is_public = (self.py_platform.startswith('linux') or self.py_platform == 'darwin')
+        self.prot_is_public = (self.py_platform.startswith('linux') or self.py_platform.startswith('freebsd') or self.py_platform == 'darwin')
 
         if pkg_config.pyqt5_is_supported and pkg_config.pyqt4_is_supported:
             pyqt = 'PyQt5' if pkg_config.pyqt5_is_default else 'PyQt4'
@@ -1549,10 +1549,10 @@ INSTALLS += sip
 
     # These optimisations could apply to other platforms.
     if module_config.no_exceptions:
-        if target_config.py_platform.startswith('linux') or target_config.py_platform == 'darwin':
+        if target_config.py_platform.startswith('linux') or target_config.py_platform.startswith('freebsd') or target_config.py_platform == 'darwin':
             pro.write('QMAKE_CXXFLAGS += -fno-exceptions\n')
 
-    if target_config.py_platform.startswith('linux') and not opts.static:
+    if target_config.py_platform.startswith('linux') or target_config.py_platform.startswith('freebsd') and not opts.static:
         if target_config.py_version >= 0x030000:
             entry_point = 'PyInit_%s' % mname
         else:
