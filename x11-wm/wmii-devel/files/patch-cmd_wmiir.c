--- cmd/wmiir.c.orig	2020-10-18 16:14:32 UTC
+++ cmd/wmiir.c
@@ -1,6 +1,7 @@
 /* Copyight ©2007-2010 Kris Maglione <fbsdaemon@gmail.com>
  * See LICENSE file for license details.
  */
+#define EXTERN
 #define IXP_NO_P9_
 #define IXP_P9_STRUCTS
 #include <stdio.h>
