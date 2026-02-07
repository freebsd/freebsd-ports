--- src/3rdparty/masm/assembler/ARM64Assembler.h.orig	2018-06-15 11:30:15 UTC
+++ src/3rdparty/masm/assembler/ARM64Assembler.h
@@ -3036,6 +3036,8 @@ class ARM64Assembler { (public)
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif OS(FREEBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(QNX)
 #if !ENABLE(ASSEMBLER_WX_EXCLUSIVE)
         msync(code, size, MS_INVALIDATE_ICACHE);
