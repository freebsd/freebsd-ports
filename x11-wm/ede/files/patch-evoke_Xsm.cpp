--- evoke/Xsm.cpp.orig	2014-06-21 21:24:41 UTC
+++ evoke/Xsm.cpp
@@ -523,7 +523,7 @@ bool Xsm::load_serialized(void) {
 	 * this will load SETTINGS_FILENAME only from local directory;
 	 * intended for development and testing only
 	 */
-	String file = SETTINGS_FILENAME".conf";
+	String file = SETTINGS_FILENAME ".conf";
 #else
 	/* try to find it in home directory, then will scan for the system one */
 	String file = Resource::find_config(SETTINGS_FILENAME);
@@ -647,10 +647,10 @@ bool Xsm::save_serialized(void) {
 	 * this will load SETTINGS_FILENAME only from local directory;
 	 * intended for development and testing only
 	 */
-	String file = SETTINGS_FILENAME".conf";
+	String file = SETTINGS_FILENAME ".conf";
 #else
 	String file = user_config_dir();
-	file += "/ede/"SETTINGS_FILENAME".conf";
+	file += "/ede/" SETTINGS_FILENAME ".conf";
 #endif
 
 	FILE* setting_file = fopen(file.c_str(), "w");
