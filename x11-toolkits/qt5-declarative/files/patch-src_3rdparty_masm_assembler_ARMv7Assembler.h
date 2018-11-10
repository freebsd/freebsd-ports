--- src/3rdparty/masm/assembler/ARMv7Assembler.h.orig	2018-06-15 11:30:15 UTC
+++ src/3rdparty/masm/assembler/ARMv7Assembler.h
@@ -2372,6 +2372,8 @@ class ARMv7Assembler { (public)
         UNUSED_PARAM(code);
         UNUSED_PARAM(size);
 #endif
+#elif OS(FREEBSD) && COMPILER(CLANG)
+	__clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
