--- extras/FreeType/lib/ttcalc.c.orig	Wed Jan 15 17:48:58 2003
+++ extras/FreeType/lib/ttcalc.c	Wed Jan 15 17:49:03 2003
@@ -84,7 +84,7 @@
 
     while ( z )
     {
-      z = (unsigned INT64)z >> 1;
+      z = (CARD64)z >> 1;
       j++;
     }
     return j - 1;
