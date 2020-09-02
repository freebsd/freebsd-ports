--- dmenu.c.orig	2019-06-25 12:55:46 UTC
+++ dmenu.c
@@ -40,6 +40,7 @@ struct {
 	int32_t scroll_right;
 } window_config;
 
+const char *progname;
 
 static uint32_t color_bg = 0x222222ff;
 static uint32_t color_fg = 0xbbbbbbff;
