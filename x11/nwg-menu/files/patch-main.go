- Adapt to BSD-style shutdown

--- main.go.orig	1979-11-29 15:00:00 UTC
+++ main.go
@@ -122,8 +122,8 @@ var cmdLogout = flag.String("cmd-logout", "swaymsg exi
 var wm = flag.String("wm", "", "use swaymsg exec (with 'sway' argument) or hyprctl dispatch exec (with 'hyprland') or riverctl spawn (with 'river') to launch programs")
 var cmdLock = flag.String("cmd-lock", "swaylock -f -c 000000", "screen lock command")
 var cmdLogout = flag.String("cmd-logout", "swaymsg exit", "logout command")
-var cmdRestart = flag.String("cmd-restart", "systemctl reboot", "reboot command")
-var cmdShutdown = flag.String("cmd-shutdown", "systemctl -i poweroff", "shutdown command")
+var cmdRestart = flag.String("cmd-restart", "shutdown -r now", "reboot command")
+var cmdShutdown = flag.String("cmd-shutdown", "shutdown -p now", "shutdown command")
 var debug = flag.Bool("debug", false, "turn on Debug messages")
 var hover = flag.Bool("t", false, "hovering caTegories opens submenus")
 var clickOutside = flag.Bool("k", false, "clicKing outside closes the window")
