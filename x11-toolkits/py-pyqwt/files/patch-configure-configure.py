--- configure/configure.py.orig	2009-08-17 05:24:49.000000000 +0800
+++ configure/configure.py	2009-08-17 05:25:10.000000000 +0800
@@ -183,7 +183,7 @@
 ''' % ' '.join(extra_include_dirs))
     f.close()
 
-    qmake = os.path.join(configuration.qt_dir, 'bin', 'qmake')
+    qmake = os.path.join(configuration.qt_dir, 'bin', 'qmake-qt4')
     os.system('%s -spec %s -o %s %s' % (
         qmake, configuration.platform, make_file, pro_file))
 
