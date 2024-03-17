--- src/gs-auth-pwent.c.orig	2023-03-20 15:38:27 UTC
+++ src/gs-auth-pwent.c
@@ -37,10 +37,12 @@
 # include <unistd.h>
 #endif
 
-#ifdef HAVE_LIBCRYPT
-# include <crypt.h>
-#else
-# define crypt(a, b) NULL
+#if !defined(__FreeBSD__)
+# ifdef HAVE_LIBCRYPT
+#  include <crypt.h>
+# else
+#  define crypt(a, b) NULL
+# endif
 #endif
 
 #ifdef __bsdi__
