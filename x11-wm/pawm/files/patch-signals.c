$FreeBSD$

--- src/signals.c.orig	Sun Jul  6 22:45:30 2003
+++ src/signals.c	Fri Aug 22 04:54:29 2003
@@ -22,6 +22,7 @@
 */
 
 
+#include <sys/types.h>
 #include "signals.h"
 
 /* Non-ignored signals. This array marks its end with '0',
