--- src/config.h.orig	2021-10-07 13:58:27 UTC
+++ src/config.h
@@ -89,6 +89,7 @@ struct config
 	char* shutdown_cmd;
 	char* term_reset_cmd;
 	uint8_t tty;
+	uint8_t vt;
 	char* wayland_cmd;
 	bool wayland_specifier;
 	char* waylandsessions;
