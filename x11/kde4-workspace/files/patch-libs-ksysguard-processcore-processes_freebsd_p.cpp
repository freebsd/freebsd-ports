--- ../libs/ksysguard/processcore/processes_freebsd_p.cpp.orig	2008-04-15 00:09:17.000000000 +0200
+++ ../libs/ksysguard/processcore/processes_freebsd_p.cpp	2008-04-15 03:41:27.000000000 +0200
@@ -78,9 +78,11 @@
     process->setTracerpid(0);
 
 
-#if defined(__FreeBSD__) && __FreeBSD_version >= 500015
-    process->setUid(p->ki_uid);    
-    process->setGid(p->ki_pgid);
+#if defined(__FreeBSD__)
+    process->setEuid(p->ki_uid);    
+    process->setUid(p->ki_ruid);
+    process->setEgid(p->ki_svgid);
+    process->setGid(p->ki_rgid);
     process->setName(QString(p->ki_comm ? p->ki_comm : "????"));
 #elif defined(__DragonFly__) && __DragonFly_version >= 190000
     process->setUid(p->kp_uid);
@@ -96,13 +98,15 @@
 {
     int status;
     struct rusage pru;
-#if defined(__FreeBSD__) && __FreeBSD_version >= 500015
-        ps->setUserTime(p->ki_runtime / 10000);
+#if defined(__FreeBSD__)
+        ps->setUserTime(p->ki_rusage.ru_utime.tv_sec * 100 + p->ki_rusage.ru_utime.tv_usec / 10000);
+        ps->setSysTime(p->ki_rusage.ru_stime.tv_sec * 100 + p->ki_rusage.ru_stime.tv_usec / 10000);
         ps->setNiceLevel(p->ki_nice);
-        ps->setVmSize(p->ki_size);
-        ps->setVmRSS(p->ki_rssize * getpagesize());
+        ps->setVmSize(p->ki_size / 1024);
+        ps->setVmRSS(p->ki_rssize * getpagesize() / 1024);
         status = p->ki_stat;
-#elif defined(__DragonFly__) && __DragonFly_version >= 190000
+#elif defined(__DragonFly__) 
+#if __DragonFly_version >= 190000
         if (!getrusage(p->kp_pid, &pru)) {
             errx(1, "failed to get rusage info");
         }
@@ -119,22 +123,22 @@
         status = p->kp_proc.p_stat;
 #endif
         ps->setSysTime(0);
+#endif
 
 // "idle","run","sleep","stop","zombie"
     switch( status ) {
-      case '0':
-        ps->setStatus(Process::DiskSleep);
-	break;
-      case '1':
-        ps->setStatus(Process::Running);
-	break;
-      case '2':
-        ps->setStatus(Process::Sleeping);
-	break;
-      case '3':
-        ps->setStatus(Process::Stopped);
-	break;
-      case '4':
+      case SRUN:
+         ps->setStatus(Process::Running);
+	 break;
+      case SSLEEP:
+      case SWAIT:
+      case SLOCK:
+         ps->setStatus(Process::Sleeping);
+	 break;
+      case SSTOP:
+         ps->setStatus(Process::Stopped);
+         break;
+      case SZOMB:
          ps->setStatus(Process::Zombie);
          break;
       default:
@@ -145,10 +149,7 @@
 
 void ProcessesLocal::Private::readProcStatm(struct kinfo_proc *p, Process *process)
 {
-// TODO
-
-//     unsigned long shared;    
-//     process->setVmURSS(process->vmRSS - (shared * sysconf(_SC_PAGESIZE) / 1024));
+    process->setVmURSS(-1);
 }
 
 bool ProcessesLocal::Private::readProcCmdline(long pid, Process *process)
@@ -184,7 +185,7 @@
     struct kinfo_proc p;
     if(d->readProc(pid, &p))
     {
-#if defined(__FreeBSD__) && __FreeBSD_version >= 500015
+#if defined(__FreeBSD__)
         ppid = p.ki_ppid;
 #elif defined(__DragonFly__) && __DragonFly_version >= 190000
         ppid = p.kp_ppid;
@@ -218,13 +219,18 @@
     mib[0] = CTL_KERN;
     mib[1] = KERN_PROC;
     mib[2] = KERN_PROC_ALL;
-    sysctl(mib, 3, NULL, &len, NULL, 0);
-    p = (kinfo_proc *) malloc(len);
-    sysctl(mib, 3, p, &len, NULL, 0);
+    if (sysctl(mib, 3, NULL, &len, NULL, 0) == -1)
+        return pids;
+    if ((p = (kinfo_proc *) malloc(len)) == NULL)
+        return pids;    
+    if (sysctl(mib, 3, p, &len, NULL, 0) == -1) {
+	free(p);
+        return pids;
+    }
 
     for (num = 0; num < len / sizeof(struct kinfo_proc); num++)
     {
-#if defined(__FreeBSD__) && __FreeBSD_version >= 500015
+#if defined(__FreeBSD__)
         long pid = p[num].ki_pid;
         long long ppid = p[num].ki_ppid;
 #elif defined(__DragonFly__) && __DragonFly_version >= 190000
@@ -294,8 +300,11 @@
 
     size_t Total;
     size_t len;
+
     len = sizeof (Total);
-    sysctlbyname("hw.physmem", &Total, &len, NULL, 0);
+    if (sysctlbyname("hw.physmem", &Total, &len, NULL, 0) == -1)
+        return 0;
+
     return Total /= 1024;
 }
 
