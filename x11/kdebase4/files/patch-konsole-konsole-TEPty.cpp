--- konsole/konsole/TEPty.cpp.orig	Mon Sep 29 11:22:07 2003
+++ konsole/konsole/TEPty.cpp	Mon Sep 29 11:22:12 2003
@@ -624,7 +624,14 @@
   if (strncmp(str_ptr, "/dev/", 5) == 0)
        str_ptr += 5;
   strncpy(l_struct.ut_line, str_ptr, UT_LINESIZE);
-  time(&l_struct.ut_time);
+
+  // Handle 64-bit time_t properly, where it may be larger
+  // than the integral type of ut_time.
+  {
+      time_t ut_time_temp;
+      time(&ut_time_temp);
+      l_struct.ut_time=ut_time_temp;
+  }
 
   login(&l_struct);
 #endif
