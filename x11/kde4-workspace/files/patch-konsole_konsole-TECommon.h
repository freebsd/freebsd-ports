--- konsole/konsole/TECommon.h.orig	Mon Sep 18 03:31:12 2006
+++ konsole/konsole/TECommon.h	Mon Sep 18 03:31:31 2006
@@ -219,8 +219,8 @@
 
 inline bool ca::isBold(const ColorEntry* base) const
 {
-  return (b.t == CO_DFT) && base[b.u+0+(b.v?BASE_COLORS:0)].bold
-      || (b.t == CO_SYS) && base[b.u+2+(b.v?BASE_COLORS:0)].bold;
+  return (f.t == CO_DFT) && base[f.u+0+(f.v?BASE_COLORS:0)].bold
+      || (f.t == CO_SYS) && base[f.u+2+(f.v?BASE_COLORS:0)].bold;
 }
 
 #endif // TECOMMON_H
