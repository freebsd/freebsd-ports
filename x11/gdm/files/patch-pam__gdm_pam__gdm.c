--- pam_gdm/pam_gdm.c.orig	2022-01-12 14:15:56 UTC
+++ pam_gdm/pam_gdm.c
@@ -21,11 +21,15 @@
 
 #include <unistd.h>
 
+#ifdef __linux__
 #include <security/_pam_macros.h>
 #include <security/pam_ext.h>
 #include <security/pam_misc.h>
 #include <security/pam_modules.h>
 #include <security/pam_modutil.h>
+#else
+#include <security/pam_modules.h>
+#endif
 
 #ifdef HAVE_KEYUTILS
 #include <keyutils.h>
