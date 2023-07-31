--- src/config.c.orig	2023-07-31 13:38:18 UTC
+++ src/config.c
@@ -11,8 +11,8 @@
 #include <unistd.h>
 
 #ifndef DEBUG
-	#define INI_LANG DATADIR "/lang/%s.ini"
-	#define INI_CONFIG "/etc/ly/config.ini"
+	#define INI_LANG "/usr/local/etc/ly/lang/%s.ini"
+	#define INI_CONFIG "/usr/local/etc/ly/config.ini"
 #else
 	#define INI_LANG "../res/lang/%s.ini"
 	#define INI_CONFIG "../res/config.ini"
@@ -190,6 +190,7 @@ void config_load(const char *cfg_path)
 		{"shutdown_key", &config.shutdown_key, config_handle_str},
 		{"term_reset_cmd", &config.term_reset_cmd, config_handle_str},
 		{"tty", &config.tty, config_handle_u8},
+		{"vt", &config.vt, config_handle_u8},
 		{"wayland_cmd", &config.wayland_cmd, config_handle_str},
 		{"wayland_specifier", &config.wayland_specifier, config_handle_bool},
 		{"waylandsessions", &config.waylandsessions, config_handle_str},
@@ -200,7 +201,7 @@ void config_load(const char *cfg_path)
 		{"xsessions", &config.xsessions, config_handle_str},
 	};
 
-	uint16_t map_len[] = {41};
+	uint16_t map_len[] = {42};
 	struct configator_param* map[] =
 	{
 		map_no_section,
@@ -302,6 +303,7 @@ void config_defaults()
 	config.shutdown_key = strdup("F1");
 	config.term_reset_cmd = strdup("/usr/bin/tput reset");
 	config.tty = 2;
+	config.vt = 9;
 	config.wayland_cmd = strdup(DATADIR "/wsetup.sh");
 	config.wayland_specifier = false;
 	config.waylandsessions = strdup("/usr/share/wayland-sessions");
