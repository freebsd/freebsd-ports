--- src/config.c.orig	2020-02-02 23:51:05.000000000 -0800
+++ src/config.c	2021-02-02 19:41:09.071495000 -0800
@@ -9,8 +9,8 @@
 #include <unistd.h>
 
 #ifndef DEBUG
-	#define INI_LANG DATADIR "/lang/%s.ini"
-	#define INI_CONFIG "/etc/ly/config.ini"
+	#define INI_LANG "%%ETCDIR%%/lang/%s.ini"
+	#define INI_CONFIG "%%ETCDIR%%/config.ini"
 #else
 	#define INI_LANG "../res/lang/%s.ini"
 	#define INI_CONFIG "../res/config.ini"
@@ -183,6 +183,7 @@
 		{"shutdown_cmd", &config.shutdown_cmd, config_handle_str},
 		{"term_reset_cmd", &config.term_reset_cmd, config_handle_str},
 		{"tty", &config.tty, config_handle_u8},
+		{"vt", &config.vt, config_handle_u8},
 		{"wayland_cmd", &config.wayland_cmd, config_handle_str},
 		{"wayland_specifier", &config.wayland_specifier, config_handle_bool},
 		{"waylandsessions", &config.waylandsessions, config_handle_str},
@@ -192,7 +193,7 @@
 		{"xsessions", &config.xsessions, config_handle_str},
 	};
 
-	uint16_t map_len[] = {34};
+	uint16_t map_len[] = {35};
 	struct configator_param* map[] =
 	{
 		map_no_section,
@@ -289,6 +290,7 @@
 	config.shutdown_cmd = strdup("/sbin/shutdown -a now");
 	config.term_reset_cmd = strdup("/usr/bin/tput reset");
 	config.tty = 2;
+	config.vt = 9;
 	config.wayland_cmd = strdup(DATADIR "/wsetup.sh");
 	config.wayland_specifier = false;
 	config.waylandsessions = strdup("/usr/share/wayland-sessions");
