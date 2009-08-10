--- ./ConfigureChecks.cmake.orig	2009-06-09 20:09:30.000000000 +0400
+++ ./ConfigureChecks.cmake	2009-08-06 13:42:18.000000000 +0400
@@ -144,11 +144,11 @@
 
   set(UTIL_LIBRARY)
 
-  check_library_exists(utempter addToUtmp "" HAVE_ADDTOUTEMP)
-  check_include_files(utempter.h HAVE_UTEMPTER_H)
+  check_library_exists(utempter addToUtmp "/usr/local/lib" HAVE_ADDTOUTEMP)
+  check_include_files(/usr/local/include/utempter.h HAVE_UTEMPTER_H)
   if (HAVE_ADDTOUTEMP AND HAVE_UTEMPTER_H)
     set(HAVE_UTEMPTER 1)
-    set(UTEMPTER_LIBRARY utempter)
+    set(UTEMPTER_LIBRARY /usr/local/lib/libutempter.so)
   else (HAVE_ADDTOUTEMP AND HAVE_UTEMPTER_H)
     check_function_exists(login login_in_libc)
     if (NOT login_in_libc)
