--- kittens/choose/unix_compat.c.orig	2022-11-07 10:06:42 UTC
+++ kittens/choose/unix_compat.c
@@ -19,7 +19,7 @@
 #endif
 
 int
-cpu_count() {
+cpu_count(void) {
     return sysconf(_SC_NPROCESSORS_ONLN);
 }
 
