--- lxqt-session/src/procreaper.cpp.orig	2021-04-16 16:36:14 UTC
+++ lxqt-session/src/procreaper.cpp
@@ -30,7 +30,13 @@
 #if defined(Q_OS_LINUX)
 #include <sys/prctl.h>
 #include <proc/readproc.h>
+#elif defined(Q_OS_FREEBSD)
+#include <sys/procctl.h>
+#include <libutil.h>
+#include <sys/user.h>
+#include <signal.h>
 #endif
+#include <unistd.h>
 #include <cstring>
 #include <cerrno>
 #include <sys/wait.h>
@@ -42,6 +48,10 @@ ProcReaper::ProcReaper()
     int result = prctl(PR_SET_CHILD_SUBREAPER, 1);
     if (result != 0)
         qCWarning(SESSION) << "Unable to to set PR_SET_CHILD_SUBREAPER, " << result << " - " << strerror(errno);
+#elif defined(Q_OS_FREEBSD)
+    int result = procctl(P_PID, ::getpid(), PROC_REAP_ACQUIRE, nullptr);
+    if (result != 0)
+        qCWarning(SESSION) << "Unable to to set PROC_REAP_ACQUIRE, " << result << " - " << strerror(errno);
 #endif
 }
 
@@ -92,20 +102,41 @@ void ProcReaper::stop(const std::set<int64_t> & exclud
             return;
     }
     // send term to all children
-#if defined(Q_OS_LINUX)
     const pid_t my_pid = ::getpid();
+    std::vector<pid_t> children;
+#if defined(Q_OS_LINUX)
     PROCTAB * proc_dir = ::openproc(PROC_FILLSTAT);
     while (proc_t * proc = ::readproc(proc_dir, nullptr))
     {
-        if (proc->ppid == my_pid && excludedPids.count(proc->ppid) == 0)
+        if (proc->ppid == my_pid)
         {
-            qCDebug(SESSION) << "Seding TERM to child " << proc->tgid;
-            ::kill(proc->tgid, SIGTERM);
+            children.push_back(proc->tgid);
         }
         ::freeproc(proc);
     }
     ::closeproc(proc_dir);
+#elif defined(Q_OS_FREEBSD)
+    int cnt = 0;
+    if (kinfo_proc *proc_info = kinfo_getallproc(&cnt))
+    {
+        for (int i = 0; i < cnt; ++i)
+        {
+            if (proc_info[i].ki_ppid == my_pid)
+            {
+                children.push_back(proc_info[i].ki_pid);
+            }
+        }
+        free(proc_info);
+    }
 #endif
+    for (auto const & child : children)
+    {
+        if (excludedPids.count(child) == 0)
+        {
+            qCDebug(SESSION) << "Seding TERM to child " << child;
+            ::kill(child, SIGTERM);
+        }
+    }
     mWait.wakeAll();
     {
         QMutexLocker guard{&mMutex};
