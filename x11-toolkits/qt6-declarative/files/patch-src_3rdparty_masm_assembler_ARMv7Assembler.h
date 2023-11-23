--- src/3rdparty/masm/assembler/ARMv7Assembler.h.orig	2023-09-07 12:16:06 UTC
+++ src/3rdparty/masm/assembler/ARMv7Assembler.h
@@ -2374,6 +2374,8 @@ class ARMv7Assembler { (public)
         UNUSED_PARAM(code);
         UNUSED_PARAM(size);
 #endif
+#elif OS(FREEBSD) && COMPILER(CLANG)
+	__clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
