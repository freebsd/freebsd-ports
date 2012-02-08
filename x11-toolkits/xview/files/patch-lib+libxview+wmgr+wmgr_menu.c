--- lib/libxview/wmgr/wmgr_menu.c.orig	2005-03-28 06:41:51.000000000 -0800
+++ lib/libxview/wmgr/wmgr_menu.c	2012-02-03 12:56:34.963007532 -0800
@@ -14,8 +14,8 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
-#if defined(sparc) || defined(__linux__) || defined(__CYGWIN__)
-#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__)
+#if defined(sparc) || defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)
+#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)
 #include <unistd.h>
 #else
 #include <vfork.h>
