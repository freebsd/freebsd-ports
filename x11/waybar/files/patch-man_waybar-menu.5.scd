--- man/waybar-menu.5.scd.orig	2026-02-06 20:15:03 UTC
+++ man/waybar-menu.5.scd
@@ -91,10 +91,10 @@ Module config :
 	"menu": "on-click",
 	"menu-file": "~/.config/waybar/power_menu.xml",
 	"menu-actions": {
-		"shutdown": "shutdown",
-		"reboot": "reboot",
-		"suspend": "systemctl suspend",
-		"hibernate": "systemctl hibernate",
+		"shutdown": "shutdown -p now",
+		"reboot": "shutdown -r now",
+		"suspend": "zzz",
+		"hibernate": "apiconf -s 4",
 	},
 },
 ```
