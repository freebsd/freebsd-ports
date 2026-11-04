--- src/init/initHelpers.cpp.orig	2026-11-04 06:10:52 UTC
+++ src/init/initHelpers.cpp
@@ -1,4 +1,4 @@
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <linux/capability.h>
 #include <sys/prctl.h>
 #endif
@@ -21,7 +21,7 @@ bool NInit::isSudo() {
     return getuid() != geteuid() || !geteuid();
 }
 
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 // NixOS-specific fix to prevent all children from inheriting
 // CAP_SYS_NICE due to how the security wrapper works.
 void NInit::lowerAmbientCaps() {
