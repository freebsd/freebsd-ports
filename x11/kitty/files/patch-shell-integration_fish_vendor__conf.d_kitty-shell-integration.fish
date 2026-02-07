--- shell-integration/fish/vendor_conf.d/kitty-shell-integration.fish.orig	1979-11-29 23:00:00 UTC
+++ shell-integration/fish/vendor_conf.d/kitty-shell-integration.fish
@@ -126,7 +126,7 @@ function __ksi_schedule --on-event fish_prompt -d "Set
     # for sudo it will be clobbered by us, so only install this if sudo is not already function
     if not contains "no-sudo" $_ksi
         and test -n "$TERMINFO" -a "file" = (type -t sudo 2> /dev/null || echo "x")
-        and not test -r "/usr/share/terminfo/x/xterm-kitty" -o -r "/usr/share/terminfo/78/xterm-kitty"
+        and not test -r "%%DATADIR%%/terminfo/x/xterm-kitty" -o -r "/usr/share/terminfo/x/xterm-kitty" -o -r "/usr/share/terminfo/78/xterm-kitty"
         # Ensure terminfo is available in sudo
         function sudo
             set --local is_sudoedit "n"
