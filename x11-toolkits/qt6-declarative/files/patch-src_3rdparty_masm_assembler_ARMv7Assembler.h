--- src/3rdparty/masm/assembler/ARMv7Assembler.h.orig	2026-01-21 11:37:05 UTC
+++ src/3rdparty/masm/assembler/ARMv7Assembler.h
@@ -2381,6 +2381,8 @@ class ARMv7Assembler { (public)
 #elif OS(VXWORKS)
         ::cacheFlush(DATA_CACHE, code, size);
         ::cacheInvalidate(INSTRUCTION_CACHE, code, size);
+#elif OS(FREEBSD) && COMPILER(CLANG)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
