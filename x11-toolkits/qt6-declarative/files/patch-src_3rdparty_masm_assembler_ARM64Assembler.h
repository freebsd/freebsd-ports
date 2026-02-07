--- src/3rdparty/masm/assembler/ARM64Assembler.h.orig	2023-09-07 12:16:06 UTC
+++ src/3rdparty/masm/assembler/ARM64Assembler.h
@@ -3045,6 +3045,8 @@ class ARM64Assembler { (public)
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif OS(FREEBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(QNX)
 #if !ENABLE(ASSEMBLER_WX_EXCLUSIVE)
         msync(code, size, MS_INVALIDATE_ICACHE);
