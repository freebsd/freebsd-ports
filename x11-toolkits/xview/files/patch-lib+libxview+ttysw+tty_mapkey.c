--- lib/libxview/ttysw/tty_mapkey.c.orig	Tue Jun 29 00:17:20 1993
+++ lib/libxview/ttysw/tty_mapkey.c	Fri Oct 17 09:54:12 2003
@@ -12,7 +12,8 @@
 
 #include <stdio.h>
 #include <ctype.h>
-#ifdef SVR4
+#include <sys/param.h>
+#if (defined(BSD4_4) || defined(SVR4))
 #include <string.h>
 #endif
 #include <sys/types.h>
@@ -500,7 +501,7 @@
  * have more time.
  */
 
-#ifdef i386
+#if defined(i386) && !defined (__FreeBSD__)
 static void
 ttysw_arrow_keys_to_string(xv_id, str)
     unsigned        xv_id;
