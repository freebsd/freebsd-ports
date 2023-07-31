--- src/config.h.orig	2023-07-31 13:27:47 UTC
+++ src/config.h
@@ -94,6 +94,7 @@ struct config
 	char* shutdown_key;
 	char* term_reset_cmd;
 	uint8_t tty;
+	uint8_t vt;
 	char* wayland_cmd;
 	bool wayland_specifier;
 	char* waylandsessions;
