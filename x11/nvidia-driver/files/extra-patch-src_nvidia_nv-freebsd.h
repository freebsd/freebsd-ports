--- src/nvidia/nv-freebsd.h.orig	2015-10-30 22:40:02 UTC
+++ src/nvidia/nv-freebsd.h
@@ -144,6 +144,11 @@ MALLOC_DECLARE(M_NVIDIA);
 #endif
 
 /*
+ * Enable/Disable support for PAE on i386.
+ */
+#undef NV_SUPPORT_PAE
+
+/*
  * Enable/Disable support for ACPI Power Management.
  */
 
