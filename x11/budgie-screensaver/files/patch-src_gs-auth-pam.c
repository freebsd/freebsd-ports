--- src/gs-auth-pam.c.orig	2022-06-11 04:30:52 UTC
+++ src/gs-auth-pam.c
@@ -33,8 +33,7 @@
 #include <pwd.h>
 #include <grp.h>
 #include <security/pam_appl.h>
-#include <security/pam_modutil.h>
-#include <security/pam_ext.h>
+#include <security/pam_modules.h>
 #include <signal.h>
 #include <errno.h>
 
