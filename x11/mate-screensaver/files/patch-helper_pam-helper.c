--- helper/pam-helper.c.orig	2021-11-15 14:28:47.000000000 -0800
+++ helper/pam-helper.c	2021-12-28 19:09:39.501645000 -0800
@@ -33,7 +33,6 @@
  */
 
 #include <security/pam_appl.h>
-#include <security/_pam_macros.h>
 
 #include <sys/types.h>
 #include <stdarg.h>
