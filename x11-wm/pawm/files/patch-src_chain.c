$FreeBSD$

FreeBSD 4 is not C99-compliant.

--- src/chain.c.orig	Wed Aug  6 14:27:17 2003
+++ src/chain.c	Sat Oct 18 16:30:50 2003
@@ -22,7 +22,7 @@ Copyright (C) 2002,03 Raúl Núñez de Aren
 #include <stddef.h>
 #include <errno.h>
 #include <limits.h>
-#include <stdint.h>
+#include <sys/types.h>
 #include "chain.h"
 #include "mobs.h"
 
@@ -199,7 +199,7 @@ void *chain_put (Chain chain, void *item
     ASSERT(chain);
     ASSERT(item);
 
-    if (chain->size==SIZE_MAX) {
+    if (chain->size==UINT_MAX) {
         errno=EFBIG;
         return NULL;
     }
