- Adapt to BSD-style shutdown

--- main.go.orig	2024-09-21 00:07:27 UTC
+++ main.go
@@ -121,8 +121,8 @@ var cmdLogout = flag.String("cmd-logout", "swaymsg exi
 var wm = flag.String("wm", "", "use swaymsg exec (with 'sway' argument) or hyprctl dispatch exec (with 'hyprland') or riverctl spawn (with 'river') to launch programs")
 var cmdLock = flag.String("cmd-lock", "swaylock -f -c 000000", "screen lock command")
 var cmdLogout = flag.String("cmd-logout", "swaymsg exit", "logout command")
-var cmdRestart = flag.String("cmd-restart", "systemctl reboot", "reboot command")
-var cmdShutdown = flag.String("cmd-shutdown", "systemctl -i poweroff", "shutdown command")
+var cmdRestart = flag.String("cmd-restart", "shutdown -r now", "reboot command")
+var cmdShutdown = flag.String("cmd-shutdown", "shutdown -p now", "shutdown command")
 var debug = flag.Bool("debug", false, "Turn on Debug messages")
 
 func main() {
