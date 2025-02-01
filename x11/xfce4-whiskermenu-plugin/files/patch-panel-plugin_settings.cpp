--- panel-plugin/settings.cpp.orig	2025-01-30 14:00:16 UTC
+++ panel-plugin/settings.cpp
@@ -188,6 +188,7 @@ void Settings::load(const gchar* file, bool is_default
 {
 	if (!file)
 	{
+		command[CommandProfile]->set_shown(false);
 		return;
 	}
 
