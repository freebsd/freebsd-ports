# Official fixes for 32-bit compilation
--- src/transition/script.h.orig	2024-09-28 23:22:13 UTC
+++ src/transition/script.h
@@ -45,8 +45,6 @@ typedef struct config_setting_t config_setting_t;
 	SCRIPT_EVAL_OK,
 };
 typedef struct config_setting_t config_setting_t;
-static_assert(alignof(double) > alignof(unsigned), "double/unsigned has unexpected "
-                                                   "alignment");
 
 #define SCRIPT_CTX_PLACEHOLDER_BASE (0x40000000)
 
