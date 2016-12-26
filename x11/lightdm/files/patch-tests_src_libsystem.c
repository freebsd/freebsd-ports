--- tests/src/libsystem.c.orig	2016-11-13 22:45:48 UTC
+++ tests/src/libsystem.c
@@ -20,7 +20,6 @@
 #include <security/pam_appl.h>
 #include <fcntl.h>
 #include <dlfcn.h>
-#include <utmp.h>
 #include <utmpx.h>
 #ifdef __linux__
 #include <linux/vt.h>
