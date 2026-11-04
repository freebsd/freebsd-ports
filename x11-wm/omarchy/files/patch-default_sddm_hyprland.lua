--- default/sddm/hyprland.lua.orig
+++ default/sddm/hyprland.lua
@@ -1,6 +1,12 @@
 -- Minimal Hyprland config for the SDDM Wayland greeter.
 -- SDDM starts the greeter itself after the compositor is ready.
 hl.config({
+  -- The greeter must show authentication, never compositor update prompts.
+  ecosystem = {
+    no_update_news = true,
+    no_donation_nag = true,
+  },
+
   misc = {
     disable_hyprland_logo = true,
     disable_splash_rendering = true,
