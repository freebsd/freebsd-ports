$FreeBSD$

FreeBSD 4 is not C99-compliant.

--- src/timux.h.orig	Wed Apr 24 11:07:32 2002
+++ src/timux.h	Sat Oct 18 17:15:40 2003
@@ -25,13 +25,11 @@
 #ifndef __X_TIMUX_X__
 #define __X_TIMUX_X__
 
-#include <stdint.h>
-
 /* NOTE: timestamps, and so resolutions, are expressed in milliseconds */
 
 typedef struct TiMux *TiMux;
-typedef uint_fast32_t tempus;
-typedef uint_fast64_t jobid;
+typedef uint32_t tempus;
+typedef uint64_t jobid;
 typedef void (*duty) (void *);
 
 TiMux timux_create (void);
