--- astro.c.orig	2023-06-03 14:41:54 UTC
+++ astro.c
@@ -7,7 +7,7 @@
 #include <math.h>
 #include "mathlocal.h"
 
-long		time();
+time_t		time();
 long		jdate();
 double		jtime();
 double		gmst();
