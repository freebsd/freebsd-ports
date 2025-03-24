--- src/panel/settings/themes.vala.orig	2025-03-22 02:24:35 UTC
+++ src/panel/settings/themes.vala
@@ -15,7 +15,6 @@ public enum ThemeType {
 	CURSOR_THEME
 }
 
-[Compact]
 class ThemeInfo : GLib.Object {
 	private ThemeType theme_type;
 	private List<string> paths;
