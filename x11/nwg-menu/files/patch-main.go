- Adapt to BSD-style shutdown

--- main.go.orig	2021-06-19 23:37:36 UTC
+++ main.go
@@ -119,8 +119,8 @@ var fileManager = flag.String("fm", "thunar", "File Ma
 var term = flag.String("term", "alacritty", "Terminal emulator")
 var cmdLock = flag.String("cmd-lock", "swaylock -f -c 000000", "screen lock command")
 var cmdLogout = flag.String("cmd-logout", "swaymsg exit", "logout command")
-var cmdRestart = flag.String("cmd-restart", "systemctl reboot", "reboot command")
-var cmdShutdown = flag.String("cmd-shutdown", "systemctl -i poweroff", "shutdown command")
+var cmdRestart = flag.String("cmd-restart", "shutdown -r now", "reboot command")
+var cmdShutdown = flag.String("cmd-shutdown", "shutdown -p now", "shutdown command")
 
 func main() {
 	timeStart := time.Now()
