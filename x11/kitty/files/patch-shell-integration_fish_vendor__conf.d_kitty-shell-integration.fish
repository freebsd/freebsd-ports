--- shell-integration/fish/vendor_conf.d/kitty-shell-integration.fish.orig	1979-11-29 23:00:00 UTC
+++ shell-integration/fish/vendor_conf.d/kitty-shell-integration.fish
@@ -141,7 +141,7 @@ function __ksi_schedule --on-event fish_prompt -d "Set
     # for sudo/run0 it will be clobbered by us, so only install these if they are not already functions
     if not contains "no-sudo" $_ksi
         and test -n "$TERMINFO"
-        and not test -r "/usr/share/terminfo/x/xterm-kitty" -o -r "/usr/share/terminfo/78/xterm-kitty"
+        and not test -r "%%DATADIR%%/terminfo/x/xterm-kitty" -o -r "/usr/share/terminfo/x/xterm-kitty" -o -r "/usr/share/terminfo/78/xterm-kitty"
         if test "file" = (type -t sudo 2> /dev/null || echo "x")
             # Ensure terminfo is available in sudo
             function sudo
