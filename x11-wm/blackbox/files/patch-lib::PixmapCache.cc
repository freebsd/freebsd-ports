--- lib/PixmapCache.cc.old	Fri Mar 11 09:46:02 2005
+++ lib/PixmapCache.cc	Fri Mar 11 09:32:16 2005
@@ -97,7 +97,7 @@
 
 
   static RealPixmapCache *realpixmapcache = 0;
-  static unsigned long maxmem_usage = 2ul*1024ul*1024ul; // 2mb default
+  static unsigned long maxmem_usage = 8ul*1024ul*1024ul; // 8MB default
   static unsigned long mem_usage = 0ul;
 
 
