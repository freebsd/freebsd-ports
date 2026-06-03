--- src/init/initHelpers.cpp.orig	2026-05-31 08:07:11 UTC
+++ src/init/initHelpers.cpp
@@ -1,5 +1,7 @@
+#if defined(__linux__)
 #include <linux/capability.h>
 #include <sys/prctl.h>
+#endif
 
 #include "initHelpers.hpp"
 
@@ -26,11 +28,13 @@ void NInit::gainRealTime() {
 
     // NixOS-specific fix to prevent all children from inheriting
     // CAP_SYS_NICE due to how the security wrapper works.
+#if defined(__linux__)
     prctl(PR_CAP_AMBIENT, PR_CAP_AMBIENT_LOWER, CAP_SYS_NICE, 0, 0);
+#endif
 
     pthread_atfork(nullptr, nullptr, []() {
         const struct sched_param param = {.sched_priority = 0};
         if (pthread_setschedparam(pthread_self(), SCHED_OTHER, &param))
             Log::logger->log(Log::WARN, "Failed to reset process scheduling strategy");
     });
-}
\ No newline at end of file
+}
