--- src/gtk+-2.x/ctkdisplayconfig-utils.c.orig	2011-09-24 11:57:57.000000000 +0900
+++ src/gtk+-2.x/ctkdisplayconfig-utils.c	2012-04-08 00:33:01.000000000 +0900
@@ -1391,7 +1391,7 @@
                                        NvCtrlGetTargetId(screen->gpu->handle),
                                        orig_mode_str);
             nv_error_msg(*err_str);
-            goto fail;
+            continue;
         }
 
 
