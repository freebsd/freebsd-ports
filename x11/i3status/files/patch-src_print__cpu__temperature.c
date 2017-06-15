--- src/print_cpu_temperature.c.orig	2017-01-30 07:58:44 UTC
+++ src/print_cpu_temperature.c
@@ -13,7 +13,7 @@
 #include <err.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
-#define TZ_ZEROC 2732
+#define TZ_ZEROC 2731
 #define TZ_KELVTOC(x) (((x)-TZ_ZEROC) / 10), abs(((x)-TZ_ZEROC) % 10)
 #define TZ_AVG(x) ((x)-TZ_ZEROC) / 10
 #endif
