--- configure.py.orig	2021-10-26 11:10:38 UTC
+++ configure.py
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
