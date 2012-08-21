--- src/gtk+-2.x/ctkdisplayconfig-utils.c.orig	2011-09-24 11:57:57.000000000 +0900
+++ src/gtk+-2.x/ctkdisplayconfig-utils.c	2012-04-08 00:33:01.000000000 +0900
@@ -1391,7 +1391,7 @@
                                        NvCtrlGetTargetId(screen->gpu->handle),
                                        orig_mode_str);
             nv_error_msg(*err_str);
-            goto fail;
+            continue;
         }
 
 
--- src/gtk+-2.x/ctkdisplayconfig-utils.c.orig	2012-08-21 23:36:11.000000000 +0900
+++ src/gtk+-2.x/ctkdisplayconfig-utils.c	2012-08-21 23:36:46.000000000 +0900
@@ -2534,11 +2534,14 @@
     /* See if the screen is set to not scanout */
     ret = NvCtrlGetAttribute(screen->handle, NV_CTRL_NO_SCANOUT, &val);
     if (ret != NvCtrlSuccess) {
+#if 0
         *err_str = g_strdup_printf("Failed to query NoScanout for "
                                    "screen %d.",
                                    screen_id);
         nv_warning_msg(*err_str);
         goto fail;
+#endif
+        val = NV_CTRL_NO_SCANOUT_DISABLED;
     }
     screen->no_scanout = (val == NV_CTRL_NO_SCANOUT_ENABLED);
 
