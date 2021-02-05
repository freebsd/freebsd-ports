--- src/config.h.orig	2020-02-03 07:51:05 UTC
+++ src/config.h
@@ -88,6 +88,7 @@ struct config
 	char* shutdown_cmd;
 	char* term_reset_cmd;
 	u8 tty;
+	u8 vt;
 	char* wayland_cmd;
 	bool wayland_specifier;
 	char* waylandsessions;
