--- General.h.orig	1997-03-21 11:12:30 UTC
+++ General.h
@@ -40,7 +40,7 @@ typedef char Boolean;
     struct sigaction sAct; \
     (void)sigemptyset(&sAct.sa_mask); \
     sAct.sa_flags = 0; \
-    sAct.sa_handler = (SIGNAL_CALLBACK_TYPE(y)); \
+    sAct.sa_handler = y; \
     (void)sigaction((x), &sAct, NULL); \
   } while (0)
 
