--- zvt/update.c.orig	Sat Aug 24 04:22:10 2002
+++ zvt/update.c	Sat Aug 24 04:22:20 2002
@@ -848,7 +848,7 @@
   if (c>=256)
     return 1;
   ch = c&0xff;
-  return vx->wordclass[ch>>3]&(1<<(ch&7))!=0;
+  return (vx->wordclass[ch>>3]&(1<<(ch&7)))!=0;
 }
 
 /*
