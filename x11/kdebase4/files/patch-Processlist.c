--- ksysguard/ksysguardd/FreeBSD/ProcessList.c.old	Tue Jan 23 19:44:29 2001
+++ ksysguard/ksysguardd/FreeBSD/ProcessList.c	Tue Jan 23 20:19:24 2001
@@ -186,7 +186,20 @@
 	if (sysctl(mib, 4, &p, &len, NULL, 0) == -1 || !len)
 		return -1;
 
-	/* ?? */
+#if __FreeBSD_version >= 500015
+	/* Getting runtime process info */
+        ps->pid = p.ki_pid;
+        ps->ppid = p.ki_ppid;
+        strcpy(ps->name, p.ki_comm);
+        ps->uid = p.ki_uid;
+        ps->gid = p.ki_pgid;
+
+        pwent = getpwuid(ps->uid);
+	     strcpy(ps->userName, pwent ? pwent->pw_name : "????");
+        ps->priority = p.ki_priority;
+        ps->niceLevel = p.ki_nice;
+
+#else 
         ps->pid = p.kp_proc.p_pid;
         ps->ppid = p.kp_eproc.e_ppid;
         strcpy(ps->name, p.kp_proc.p_comm);
@@ -198,16 +211,30 @@
 	strcpy(ps->userName, pwent ? pwent->pw_name : "????");
         ps->priority = p.kp_proc.p_priority;
         ps->niceLevel = p.kp_proc.p_nice;
+#endif
 
         /* this isn't usertime -- it's total time (??) */
-#if __FreeBSD_version >= 300000
+#if __FreeBSD_version >= 500015
+        ps->userTime = p.ki_runtime / 10000;
+#elif __FreeBSD_version >= 300000
         ps->userTime = p.kp_proc.p_runtime / 10000;
 #else
         ps->userTime = p.kp_proc.p_rtime.tv_sec*100+p.kp_proc.p_rtime.tv_usec/100
 #endif
+
         ps->sysTime = 0;
-        ps->userLoad = p.kp_proc.p_pctcpu / 100;
         ps->sysLoad = 0;
+#if __FreeBSD_version >= 500015
+        ps->userLoad = p.ki_pctcpu / 100;
+
+        /* memory */
+        ps->vmSize =  p.ki_size * getpagesize();
+                    
+        ps->vmRss = p.ki_rssize * getpagesize();
+
+        ps->status = p.ki_stat;
+#else
+        ps->userLoad = p.kp_proc.p_pctcpu / 100;
 
         /* memory */
         ps->vmSize =  (p.kp_eproc.e_vm.vm_tsize +
@@ -216,7 +243,7 @@
         ps->vmRss = p.kp_eproc.e_vm.vm_rssize * getpagesize();
 
         ps->status = p.kp_proc.p_stat;
-
+#endif
 	return (0);
 }
 
@@ -284,8 +311,13 @@
 	p = malloc(len);
         sysctl(mib, 3, p, &len, NULL, 0);
 
+#if __FreeBSD_version >= 500015
+	for (num = 0; num < len / sizeof(struct kinfo_proc); num++)
+		updateProcess(p[num].ki_pid);
+#else
 	for (num = 0; num < len / sizeof(struct kinfo_proc); num++)
 		updateProcess(p[num].kp_proc.p_pid);
+#endif
 
 	cleanupProcessList();
 
