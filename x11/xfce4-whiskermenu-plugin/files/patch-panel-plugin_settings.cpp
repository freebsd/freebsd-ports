--- panel-plugin/settings.cpp.orig	2015-03-08 09:15:22 UTC
+++ panel-plugin/settings.cpp
@@ -148,6 +148,8 @@ void Settings::load(char* file)
 {
 	if (!file)
 	{
+		command[CommandProfile]->set_shown(false);
+		command[CommandMenuEditor]->set_shown(false);
 		return;
 	}
 
