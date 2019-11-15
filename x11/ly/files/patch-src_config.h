--- src/config.h.orig	2019-11-12 22:29:26 UTC
+++ src/config.h
@@ -82,6 +82,7 @@ struct config
 	char* shutdown_cmd;
 	char* term_reset_cmd;
 	u8 tty;
+	u8 vt;
 	char* wayland_cmd;
 	char* waylandsessions;
 	char* x_cmd;
