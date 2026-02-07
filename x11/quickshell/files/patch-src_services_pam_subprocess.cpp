--- src/services/pam/subprocess.cpp.orig	2025-10-12 00:14:14 UTC
+++ src/services/pam/subprocess.cpp
@@ -7,7 +7,9 @@
 #include <qloggingcategory.h>
 #include <qstring.h>
 #include <sched.h>
+#if defined(__linux__)
 #include <security/_pam_types.h>
+#endif
 #include <security/pam_appl.h>
 #include <unistd.h>
 
@@ -83,7 +85,11 @@ PamIpcExitCode PamSubprocess::exec(const char* configD
 	logIf(this->log) << "Starting pam session for user \"" << user << "\" with config \"" << config
 	                 << "\" in dir \"" << configDir << "\"" << std::endl;
 
+#if defined(__linux__)
 	auto result = pam_start_confdir(config, user, &conv, configDir, &handle);
+#else
+	auto result = pam_start(config, user, &conv, &handle);
+#endif
 
 	if (result != PAM_SUCCESS) {
 		logIf(true) << "Unable to start pam conversation with error \"" << pam_strerror(handle, result)
