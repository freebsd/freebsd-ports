$FreeBSD$

FreeBSD 4 is not C99-compliant.

--- src/cfgpool.h.orig	Wed Jul 10 07:33:57 2002
+++ src/cfgpool.h	Sat Oct 18 16:14:11 2003
@@ -25,21 +25,16 @@
 #ifndef __X_CFGPOOL_X__
 #define __X_CFGPOOL_X__
 
-#include <stdint.h>
 #include <limits.h>
 #include <inttypes.h>
 
-#if SSIZE_MAX > SIZE_MAX
-#error Cannot build, since SSIZE_MAX appears to be greater than SIZE_MAX!!!
-#endif
-
 typedef struct CfgPool *CfgPool;
 
 CfgPool cfgpool_create (const char *);
 CfgPool cfgpool_delete (CfgPool);
 
 char *    cfgpool_getstring  (CfgPool, const char *);
-uintmax_t cfgpool_getnatural (CfgPool, const char *, unsigned int);
-intmax_t  cfgpool_getinteger (CfgPool, const char *, unsigned int);
+u_int32_t cfgpool_getnatural (CfgPool, const char *, unsigned int);
+u_int32_t cfgpool_getinteger (CfgPool, const char *, unsigned int);
 
 #endif
