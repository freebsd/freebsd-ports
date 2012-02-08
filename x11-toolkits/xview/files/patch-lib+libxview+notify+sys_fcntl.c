--- lib/libxview/notify/sys_fcntl.c.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/sys_fcntl.c	2012-02-03 08:15:30.766090164 -0800
@@ -14,7 +14,7 @@
  * Sys_fcntl.c - Real system call to fcntl.
  */
 
-#ifndef SVR4
+#if !defined(SVR4) && !defined(__FreeBSD__)
 #if !defined(__linux__) && !defined(__CYGWIN__)
 #include <syscall.h>
 #else
