--- lib/XRes/XRes.c.orig	Wed Oct 16 02:37:26 2002
+++ lib/XRes/XRes.c	Wed May  7 23:44:38 2003
@@ -218,7 +218,13 @@
     }
 
 #ifdef LONG64
+#ifdef __sparc64__
+    /* The first assignment is to work around a bug in gcc/gas on sparc64. */
+    *bytes = rep.bytes_overflow;
+    *bytes = (*bytes * 4294967295) + rep.bytes;
+#else
     *bytes = (rep.bytes_overflow * 4294967295) + rep.bytes;
+#endif
 #else
     *bytes = rep.bytes_overflow ? 0xffffffff : rep.bytes;
 #endif
