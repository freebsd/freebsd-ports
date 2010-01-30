--- configure.py.orig	Sun May 13 20:08:01 2007
+++ configure.py	Sun May 13 20:14:01 2007
@@ -107,7 +107,7 @@
     sys.stdout.write("  -a tag  explicitly enable the qtpe module\n")
     sys.stdout.write("  -b dir  where pyuic and pylupdate will be installed [default %s]\n" % opt_pyqtbindir)
     sys.stdout.write("  -c      concatenate each module's C/C++ source files\n")
-    sys.stdout.write("  -d dir  where the PyQt modules will be installed [default %\ns]" % opt_pyqtmoddir)
+    sys.stdout.write("  -d dir  where the PyQt modules will be installed [default %s]\n" % opt_pyqtmoddir)
     sys.stdout.write("  -f      keep any existing features file (when cross-compiling) [default remove]\n")
     sys.stdout.write("  -g dir  where the Qt qconfig.h file can be found [default Qt include directory]\n")
     sys.stdout.write("  -i      enable checking of signed interpreters using the VendorID package [default disabled]\n")
@@ -1081,15 +1081,12 @@
         macros["LIBDIR_QT"] = qt_libdir
 
     # Check the Qt header files have been installed.  Quietly check for Qt v4.
-    qt4_d = os.path.join(qt_incdir, "QtCore")
+    # NO. This won't allow having both PyQt3 and PyQt4. Check for Qt3 only.
 
-    qglobal = os.path.join(qt4_d, "qglobal.h")
+    qglobal = os.path.join(qt_incdir, "qglobal.h")
 
     if not os.access(qglobal, os.F_OK):
-        qglobal = os.path.join(qt_incdir, "qglobal.h")
-
-        if not os.access(qglobal, os.F_OK):
-            sipconfig.error("qglobal.h could not be found in %s." % qt_incdir)
+        sipconfig.error("qglobal.h could not be found in %s." % qt_incdir)
 
     # Get the Qt version number.
     global qt_version
