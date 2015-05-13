--- config.py.orig	2015-04-11 19:08:36 UTC
+++ config.py
@@ -1030,6 +1030,7 @@ elif os.name == 'posix' or COMPILER == '
 
     cflags = getWxConfigValue('--cxxflags')
     cflags = cflags.split()
+    cflags.append('-std=c++11')
     if debug:
         cflags.append('-ggdb')
         cflags.append('-O0')
