--- src/config.c.orig	2019-06-26 21:11:33 UTC
+++ src/config.c
@@ -9,8 +9,8 @@
 #include <unistd.h>
 
 #ifndef DEBUG
-	#define INI_LANG "/etc/ly/lang/%s.ini"
-	#define INI_CONFIG "/etc/ly/config.ini"
+	#define INI_LANG "%%ETCDIR%%/lang/%s.ini"
+	#define INI_CONFIG "%%ETCDIR%%/config.ini"
 #else
 	#define INI_LANG "../res/lang/%s.ini"
 	#define INI_CONFIG "../res/config.ini"
@@ -179,6 +179,7 @@ void config_load()
 		{"shutdown_cmd", &config.shutdown_cmd, config_handle_str},
 		{"term_reset_cmd", &config.term_reset_cmd, config_handle_str},
 		{"tty", &config.tty, config_handle_u8},
+		{"vt", &config.vt, config_handle_u8},
 		{"wayland_cmd", &config.wayland_cmd, config_handle_str},
 		{"waylandsessions", &config.waylandsessions, config_handle_str},
 		{"x_cmd", &config.x_cmd, config_handle_str},
@@ -187,7 +188,7 @@ void config_load()
 		{"xsessions", &config.xsessions, config_handle_str},
 	};
 
-	uint16_t map_len[] = {34};
+	uint16_t map_len[] = {35};
 	struct configator_param* map[] =
 	{
 		map_no_section,
@@ -284,6 +285,7 @@ void config_defaults()
 	config.shutdown_cmd = strdup("/sbin/shutdown -a now");
 	config.term_reset_cmd = strdup("/usr/bin/tput reset");
 	config.tty = 2;
+	config.vt = 9;
 	config.wayland_cmd = strdup("/etc/ly/wsetup.sh");
 	config.waylandsessions = strdup("/usr/share/wayland-sessions");
 	config.x_cmd = strdup("/usr/bin/X");
