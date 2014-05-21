--- src/nv-freebsd.h.orig	2014-02-13 05:07:44.000000000 +0100
+++ src/nv-freebsd.h	2014-05-05 18:38:59.000000000 +0200
@@ -143,6 +143,11 @@
 #define NV_SUPPORT_ACPI_PM
 
 /*
+ * Enable/Disable support for PAE on i386.
+ */
+#undef NV_SUPPORT_PAE
+
+/*
  * Enable/Disable heavy-weight cache-flush logic. By default, the driver
  * relies on the kernel to perform cache flushes using optimized
  * routines.
