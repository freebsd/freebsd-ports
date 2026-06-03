--- src/3rdparty/masm/assembler/ARM64Assembler.h.orig	2026-01-21 11:37:05 UTC
+++ src/3rdparty/masm/assembler/ARM64Assembler.h
@@ -3050,6 +3050,8 @@ class ARM64Assembler { (public)
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif OS(FREEBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(QNX)
 #if !ENABLE(ASSEMBLER_WX_EXCLUSIVE)
         msync(code, size, MS_INVALIDATE_ICACHE);
