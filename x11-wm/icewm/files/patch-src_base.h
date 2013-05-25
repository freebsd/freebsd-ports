--- src/base.h.orig	2010-10-31 15:09:36.000000000 +0100
+++ src/base.h	2013-05-25 12:39:49.498390711 +0200
@@ -1,12 +1,6 @@
 #ifndef __BASE_H
 #define __BASE_H
 
-#if ( __GNUC__ == 3 && __GNUC_MINOR__ > 0 ) || __GNUC__ > 3
-#define deprecated __attribute__((deprecated))
-#else
-#define deprecated
-#endif
-
 /*** Atomar Data Types ********************************************************/
 
 #ifdef NEED_BOOL
