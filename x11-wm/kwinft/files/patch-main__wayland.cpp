- Emulate SCHED_RESET_ON_FORK via pthread_atfork
- Switch to pthread_setschedparam as Linux sched_setscheduler
  operates on threads contrary to POSIX

--- main_wayland.cpp.orig	2023-02-17 14:50:58 UTC
+++ main_wayland.cpp
@@ -58,7 +58,7 @@ along with this program.  If not, see <http://www.gnu.
 #include <QDebug>
 #include <QWindow>
 
-#include <sched.h>
+#include <pthread.h>
 #include <sys/resource.h>
 
 #include <iostream>
@@ -122,12 +122,17 @@ void gainRealTime()
 namespace {
 void gainRealTime()
 {
-#if HAVE_SCHED_RESET_ON_FORK
     const int minPriority = sched_get_priority_min(SCHED_RR);
     sched_param sp;
     sp.sched_priority = minPriority;
-    sched_setscheduler(0, SCHED_RR | SCHED_RESET_ON_FORK, &sp);
-#endif
+    if (pthread_setschedparam(pthread_self(), SCHED_RR, &sp))
+        return;
+
+    pthread_atfork(NULL, NULL, []() {
+        sched_param sp;
+        sp.sched_priority = 0;
+        pthread_setschedparam(pthread_self(), SCHED_OTHER, &sp);
+    });
 }
 }
 
