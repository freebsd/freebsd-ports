--- configure.py.orig	2007-08-30 03:00:48.000000000 +0200
+++ configure.py	2007-08-30 03:02:28.000000000 +0200
@@ -29,6 +29,10 @@
 import shutil
 import py_compile
 
+freebsd = False
+import sys
+if sys.platform[:-1] == 'freebsd': freebsd = True
+
 try:
     import sipconfig
 except:
@@ -146,12 +150,15 @@
 def check_gcc ():
     global opt_concat
 
-    os.system ("gcc -dumpversion > gccvers.txt")
-    m = open ('gccvers.txt', 'r')
-    vers = m.read ().strip ()
-    m.close ()
-    os.unlink ('gccvers.txt')
-    print "gcc version %s" % vers
+    if not freebsd:
+        os.system ("gcc -dumpversion > gccvers.txt")
+        m = open ('gccvers.txt', 'r')
+        vers = m.read ().strip ()
+        m.close ()
+        os.unlink ('gccvers.txt')
+        print "gcc version %s" % vers
+    else:
+        opt_concat = 0
 
     if opt_concat == None:
         if vers < "4.0.0" or vers >= "4.0.3":
