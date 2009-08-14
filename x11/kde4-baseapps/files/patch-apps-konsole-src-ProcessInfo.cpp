--- apps/konsole/src/ProcessInfo.cpp.orig	2009-04-15 12:25:25.000000000 +0200
+++ apps/konsole/src/ProcessInfo.cpp	2009-08-14 03:00:37.000000000 +0200
@@ -27,6 +27,14 @@
 #include <unistd.h>
 #include <pwd.h>
 
+// FreeBSD
+#ifdef Q_OS_FREEBSD
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <libutil.h>
+#endif
+
 // Qt
 #include <KDebug>
 #include <QtCore/QDir>
@@ -657,6 +665,120 @@
     }
 } ;
 
+#ifdef Q_OS_FREEBSD
+class FreeBSDProcessInfo : public UnixProcessInfo
+{
+public:
+    FreeBSDProcessInfo(int pid, bool readEnvironment) 
+    : UnixProcessInfo(pid,readEnvironment)
+    {
+    }
+private:
+    virtual bool readProcInfo(int pid)
+    {
+        struct kinfo_proc *kip;
+        int name[4];
+        size_t len;
+
+        name[0] = CTL_KERN;
+        name[1] = KERN_PROC;
+        name[2] = KERN_PROC_PID;
+        name[3] = pid;
+
+        len = 0;
+        if (sysctl(name, 4, NULL, &len, NULL, 0) < 0)
+            return false;
+
+        kip = static_cast<struct kinfo_proc*>(malloc(len));
+        if (kip == NULL)
+            return false;
+
+        if (sysctl(name, 4, kip, &len, NULL, 0) < 0) {
+            free(kip);
+            return false;
+        }
+
+        if (len != sizeof(*kip) || (kip->ki_structsize != sizeof(*kip)) || (kip->ki_pid != pid)) {
+            free(kip);
+            return false;
+        }
+
+        setParentPid(kip->ki_ppid);
+        setForegroundPid(kip->ki_pgid);
+        setName(kip->ki_comm);
+        setPid(pid);
+
+        setUserId(kip->ki_uid);
+        readUserName();
+
+        free(kip);
+
+        return true;
+    }
+
+    virtual bool readArguments(int pid)
+    {
+        char args[ARG_MAX];
+        int name[4];
+        size_t len;
+
+        name[0] = CTL_KERN;
+        name[1] = KERN_PROC;
+        name[2] = KERN_PROC_ARGS;
+        name[3] = pid;
+
+        len = sizeof(args);
+        if (sysctl(name, 4, args, &len, NULL, 0) < 0);
+            return false;
+
+        for (char *cp = args; cp < args + len; cp += strlen(cp) + 1)
+            addArgument(QString(cp));
+
+        return true;
+    }
+
+    virtual bool readEnvironment(int /*pid*/)
+    {
+        // Not supported in FreeBSD
+        return true;
+    }
+
+    virtual bool readCurrentDir(int pid)
+    {
+        struct kinfo_file *kif;
+        int count;
+
+        kif = kinfo_getfile(pid, &count);
+        if (kif == NULL)
+            return false;
+
+        for (int i = 0; i < count; i++) {
+            if (kif[i].kf_fd == KF_FD_TYPE_CWD) {
+                QFileInfo info(QString(kif[i].kf_path));
+                free(kif);
+
+                const bool readable = info.isReadable();
+
+                if (readable) {
+                    if(info.isSymLink())
+                        setCurrentDir(info.symLinkTarget());
+                    else
+                        setCurrentDir(info.filePath());
+                    return true;
+                } else {
+                    if (!readable)
+                        setError(PermissionsError);
+                    else
+                        setError(UnknownError);
+
+                    return false;
+                }
+            }
+        }
+    }
+};
+#endif
+
 SSHProcessInfo::SSHProcessInfo(const ProcessInfo& process)
  : _process(process)
 {
@@ -802,6 +924,8 @@
     return new LinuxProcessInfo(pid,enableEnvironmentRead);
 #elif defined(Q_OS_SOLARIS)
     return new SolarisProcessInfo(pid,enableEnvironmentRead);
+#elif defined(Q_OS_FREEBSD)
+    return new FreeBSDProcessInfo(pid,enableEnvironmentRead);
 #else
     return new NullProcessInfo(pid,enableEnvironmentRead);
 #endif
