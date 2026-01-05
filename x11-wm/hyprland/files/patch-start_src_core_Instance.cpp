--- start/src/core/Instance.cpp.orig	2026-01-04 09:38:22 UTC
+++ start/src/core/Instance.cpp
@@ -7,11 +7,17 @@
 #include <sys/poll.h>
 #include <sys/types.h>
 #include <sys/wait.h>
-#include <sys/prctl.h>
 #include <unistd.h>
 #include <ranges>
 #include <string_view>
 
+#if defined(__linux__)
+#include <sys/prctl.h>
+#elif defined(__FreeBSD__)
+#include <signal.h>
+#include <sys/procctl.h>
+#endif
+
 #include <hyprutils/os/Process.hpp>
 
 using namespace Hyprutils::OS;
@@ -41,7 +47,12 @@ void CHyprlandInstance::runHyprlandThread(bool safeMod
     int forkRet = fork();
     if (forkRet == 0) {
         // Make hyprland die on our SIGKILL
+#if defined(__linux__)
         prctl(PR_SET_PDEATHSIG, SIGKILL);
+#elif defined(__FreeBSD__)
+        int sig = SIGKILL;
+        procctl(P_PID, getpid(), PROC_PDEATHSIG_CTL, &sig);
+#endif
 
         execvp(g_state->customPath.value_or("Hyprland").c_str(), args.data());
 
@@ -164,4 +175,4 @@ bool CHyprlandInstance::run(bool safeMode) {
     m_hlThread.join();
 
     return !m_hyprlandInitialized || m_hyprlandExiting;
-}
\ No newline at end of file
+}
