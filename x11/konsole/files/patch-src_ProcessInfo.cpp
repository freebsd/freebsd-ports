--- src/ProcessInfo.cpp.orig	2014-11-01 04:17:02 UTC
+++ src/ProcessInfo.cpp
@@ -60,6 +60,9 @@
 #include <sys/syslimits.h>
 #   if defined(Q_OS_FREEBSD)
 #   include <libutil.h>
+#   include <sys/param.h>
+#   include <sys/queue.h>
+#   include <libprocstat.h>
 #   endif
 #endif
 
@@ -280,10 +283,8 @@ void ProcessInfo::setUserName(const QStr
 void ProcessInfo::setUserHomeDir()
 {
     const QString& usersName = userName();
-    if (!usersName.isEmpty())
-        _userHomeDir = KUser(usersName).homeDir();
-    else
-        _userHomeDir = QDir::homePath();
+    const QDir& homeDir(usersName.isEmpty() ? QDir::homePath() : KUser(usersName).homeDir());
+    _userHomeDir = homeDir.canonicalPath();
 }
 
 void ProcessInfo::setParentPid(int aPid)
@@ -664,26 +665,60 @@ private:
 
         managementInfoBase[0] = CTL_KERN;
         managementInfoBase[1] = KERN_PROC;
-        managementInfoBase[2] = KERN_PROC_PID;
+        managementInfoBase[2] = KERN_PROC_ARGS;
         managementInfoBase[3] = aPid;
 
         len = sizeof(args);
         if (sysctl(managementInfoBase, 4, args, &len, NULL, 0) == -1)
             return false;
 
-        const QStringList& argumentList = QString(args).split(QChar('\0'));
+        const QStringList& argumentList = QString::fromLocal8Bit(args, len).split(QChar('\0'));
 
-        for (QStringList::const_iterator it = argumentList.begin(); it != argumentList.end(); ++it) {
-            addArgument(*it);
+        foreach (const QString& value, argumentList) {
+            if (!value.isEmpty())
+                addArgument(value);
         }
 
         return true;
     }
 
     virtual bool readEnvironment(int aPid) {
-        Q_UNUSED(aPid);
-        // Not supported in FreeBSD?
-        return false;
+
+        struct procstat *prstat = procstat_open_sysctl();
+        if (prstat == NULL) {
+            return false;
+        }
+
+        unsigned int cnt;
+        kinfo_proc *procinfo = procstat_getprocs(prstat, KERN_PROC_PID, aPid, &cnt);
+        if (procinfo == NULL || cnt != 1) {
+            procstat_close(prstat);
+            return false;
+        }
+
+        // pass 0, as the third argument, as we want to have every environment
+        // variable defined -- code courtesy of procstats procstats_arg.c
+        char **envs = procstat_getenvv(prstat, procinfo, 0);
+        if (envs == NULL) {
+            procstat_close(prstat);
+            return false;
+        }
+
+        for (int i = 0; envs[i] != NULL; i++) {
+            const QString& entry = QString::fromLocal8Bit(envs[i]);
+            const int splitPos = entry.indexOf('=');
+
+            if (splitPos != -1) {
+                const QString& name = entry.mid(0, splitPos);
+                const QString& value = entry.mid(splitPos + 1, -1);
+
+                addEnvironmentBinding(name, value);
+            }
+         }
+
+         procstat_freeenvv(prstat);
+         procstat_close(prstat);
+         return true;
     }
 
     virtual bool readCurrentDir(int aPid) {
@@ -1105,8 +1140,8 @@ SSHProcessInfo::SSHProcessInfo(const Pro
                     _host = args[i];
                 }
             } else {
-                // host has already been found, this must be the command argument
-                _command = args[i];
+                // host has already been found, this must be part of the command arguments
+                _command += (_command.isEmpty() ? "" : " ") + args[i];
             }
         }
     } else {
@@ -1151,6 +1186,13 @@ QString SSHProcessInfo::format(const QSt
     // search for and replace known markers
     output.replace("%u", _user);
 
+    // provide 'user@' if user is defined -- this makes nicer
+    // remote tabs possible: "%U%h %c" => User@Host Command
+    //                                 => Host Command
+    // Depending on whether -l was passed to ssh (which is mostly not the
+    // case due to ~/.ssh/config).
+    output.replace(QLatin1String("%U"),_user.isEmpty() ? QString() : _user+"@");
+
     if (isIpAddress)
         output.replace("%h", _host);
     else
