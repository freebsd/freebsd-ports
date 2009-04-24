--- daemon/gdm-display-access-file.c.orig	2009-04-16 01:32:41.000000000 +0200
+++ daemon/gdm-display-access-file.c	2009-04-16 01:33:17.000000000 +0200
@@ -41,6 +41,9 @@
 #include "gdm-display-access-file.h"
 #include "gdm-common.h"
 
+/* OpenBSD defines 255, glibc defines 64. */
+#define HOST_NAME_MAX 64
+
 struct _GdmDisplayAccessFilePrivate
 {
         char *username;
