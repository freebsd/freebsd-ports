--- General.h.orig	Tue Jan 28 17:48:55 2003
+++ General.h	Tue Jan 28 17:49:06 2003
@@ -40,7 +40,7 @@
     struct sigaction sAct; \
     (void)sigemptyset(&sAct.sa_mask); \
     sAct.sa_flags = 0; \
-    sAct.sa_handler = (SIGNAL_CALLBACK_TYPE(y)); \
+    sAct.sa_handler = y; \
     (void)sigaction((x), &sAct, NULL); \
   } while (0)
 
