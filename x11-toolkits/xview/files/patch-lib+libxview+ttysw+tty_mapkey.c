--- lib/libxview/ttysw/tty_mapkey.c.orig	2005-03-28 06:41:31.000000000 -0800
+++ lib/libxview/ttysw/tty_mapkey.c	2012-02-03 12:18:01.439658731 -0800
@@ -12,7 +12,7 @@
 
 #include <stdio.h>
 #include <ctype.h>
-#if defined SVR4 || defined __linux__ || defined __CYGWIN__ 
+#if defined SVR4 || defined __linux__ || defined __CYGWIN__ || defined __FreeBSD__
 #include <string.h>
 #endif
 #include <sys/types.h>
@@ -507,7 +507,7 @@
  * have more time.
  */
 
-#if defined(i386) && !defined(__linux__) && !defined(__CYGWIN__)
+#if defined(i386) && !defined(__linux__) && !defined(__CYGWIN__) && !defined (__FreeBSD__)
 static void
 ttysw_arrow_keys_to_string(xv_id, str)
     unsigned        xv_id;
