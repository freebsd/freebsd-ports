--- lib/Widgets/PreferencesWindow.vala.orig	2015-04-07 07:42:22 UTC
+++ lib/Widgets/PreferencesWindow.vala
@@ -59,6 +59,12 @@ namespace Plank.Widgets
 		
 		construct
 		{
+			GLib.Intl.setlocale (LocaleCategory.ALL, "");
+			string langpack_dir = GLib.Path.build_filename ("%%PREFIX%%", "share", "locale");
+			GLib.Intl.bindtextdomain ("plank", langpack_dir);
+			GLib.Intl.bind_textdomain_codeset ("plank", "UTF-8");
+			GLib.Intl.textdomain ("plank");
+			
 			skip_pager_hint = true;
 			skip_taskbar_hint = true;
 			title = _("Preferences");
