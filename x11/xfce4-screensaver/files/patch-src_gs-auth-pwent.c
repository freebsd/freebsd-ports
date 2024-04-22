--- src/gs-auth-pwent.c.orig	2023-03-20 15:38:27 UTC
+++ src/gs-auth-pwent.c
@@ -38,7 +38,9 @@
 #endif
 
 #ifdef HAVE_LIBCRYPT
-# include <crypt.h>
+# ifndef __FreeBSD__
+#  include <crypt.h>
+# endif
 #else
 # define crypt(a, b) NULL
 #endif
