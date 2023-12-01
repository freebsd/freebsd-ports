--- shell-integration/fish/vendor_conf.d/kitty-shell-integration.fish.orig	2023-12-01 13:31:58 UTC
+++ shell-integration/fish/vendor_conf.d/kitty-shell-integration.fish
@@ -111,8 +111,8 @@ function __ksi_schedule --on-event fish_prompt -d "Set
     # Note that neither alias nor function is recursive in fish so if the user defines an alias/function
     # for sudo it will be clobbered by us, so only install this if sudo is not already function
     if not contains "no-sudo" $_ksi
-        and test -n "$TERMINFO" -a "file" = (type -t sudo)
-        and not test -r "/usr/share/terminfo/x/xterm-kitty" -o -r "/usr/share/terminfo/78/xterm-kitty" 
+        and test -n "$TERMINFO" -a "file" = "(type -t sudo)"
+        and not test -r "%%DATADIR%%/terminfo/x/xterm-kitty" -o -r "/usr/share/terminfo/x/xterm-kitty" -o -r "/usr/share/terminfo/78/xterm-kitty" 
         # Ensure terminfo is available in sudo
         function sudo
             set --local is_sudoedit "n"
