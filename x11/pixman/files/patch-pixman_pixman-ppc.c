--- pixman/pixman-ppc.c.orig	2020-08-29 23:32:58 UTC
+++ pixman/pixman-ppc.c
@@ -68,6 +68,24 @@ pixman_have_vmx (void)
     return have_vmx;
 }
 
+#elif defined (__FreeBSD__)
+#include <machine/cpu.h>
+#include <sys/auxv.h>
+
+static pixman_bool_t
+pixman_have_vmx (void)
+{
+
+    unsigned long cpufeatures;
+    int have_vmx;
+
+    if (elf_aux_info(AT_HWCAP, &cpufeatures, sizeof(cpufeatures)))
+        return FALSE;
+
+    have_vmx = cpufeatures & PPC_FEATURE_HAS_ALTIVEC;
+    return have_vmx;
+}
+
 #elif defined (__linux__)
 
 #include <sys/types.h>
