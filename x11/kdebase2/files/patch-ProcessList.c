--- ksysguard/ksysguardd/FreeBSD/ProcessList.c	Mon Jan 22 07:12:05 2001
+++ ksysguard/ksysguardd/FreeBSD/ProcessList.c.new	Mon Mar  5 08:56:20 2001
@@ -29,6 +29,9 @@
 #include <sys/time.h>
 #include <sys/param.h>
 #include <sys/user.h>
+#if __FreeBSD_version > 500015
+#include <sys/priority.h>
+#endif
 #include <unistd.h>
 #include <pwd.h>
 #include <dirent.h>
@@ -162,7 +165,6 @@
 	static char *statuses[] = { "idle","run","sleep","stop","zombie" };
 	
 	ProcessInfo* ps;
-	int userTime, sysTime;
 	struct passwd* pwent;
 	int mib[4];
 	struct kinfo_proc p;
@@ -188,40 +190,56 @@
 	if (sysctl(mib, 4, &p, &len, NULL, 0) == -1 || !len)
 		return -1;
 
+#if __FreeBSD_version >= 500015
+        ps->pid       = p.ki_pid;
+        ps->ppid      = p.ki_ppid;
+        ps->uid       = p.ki_uid;    
+        ps->gid       = p.ki_pgid;
+        ps->priority  = p.ki_pri.pri_user;
+        ps->niceLevel = p.ki_nice;
+#else
         ps->pid       = p.kp_proc.p_pid;
         ps->ppid      = p.kp_eproc.e_ppid;
         ps->uid       = p.kp_eproc.e_ucred.cr_uid;
         ps->gid       = p.kp_eproc.e_pgid;
         ps->priority  = p.kp_proc.p_priority;
         ps->niceLevel = p.kp_proc.p_nice;
+#endif
 
         /* this isn't usertime -- it's total time (??) */
-#if __FreeBSD_version >= 300000
+#if __FreeBSD_version >= 500015
+        ps->userTime = p.ki_runtime / 10000;
+#elif __FreeBSD_version >= 300000
         ps->userTime = p.kp_proc.p_runtime / 10000;
 #else
-        ps->userTime = p.kp_proc.p_rtime.tv_sec*100+p.kp_proc.p_rtime.tv_usec/100
+	 ps->userTime = p.kp_proc.p_rtime.tv_sec*100+p.kp_proc.p_rtime.tv_usec/100;
 #endif
         ps->sysTime  = 0;
-        ps->userLoad = p.kp_proc.p_pctcpu / 100;
         ps->sysLoad  = 0;
 
-        /* memory */
-        ps->vmSize   = (p.kp_eproc.e_vm.vm_tsize +
-                       p.kp_eproc.e_vm.vm_dsize +
-                       p.kp_eproc.e_vm.vm_ssize) * getpagesize();
-        ps->vmRss    = p.kp_eproc.e_vm.vm_rssize * getpagesize();
-
-        /* process name */
-        strncpy(ps->name,p.kp_proc.p_comm? p.kp_proc.p_comm:"????",sizeof(ps->name));
-        ps->name[sizeof(ps->name)-1]='\0';
-	
-        /* find out user name with the process uid */
-        pwent = getpwuid(ps->uid);
+        /* memory, process name, process uid */
+	/* find out user name with process uid */
+	pwent = getpwuid(ps->uid);
 	strncpy(ps->userName,pwent&&pwent->pw_name? pwent->pw_name:"????",sizeof(ps->userName));
-        ps->userName[sizeof(ps->userName)-1]='\0';
-	
-        /* status, a character, not a number */
-        strcpy(ps->status,(p.kp_proc.p_stat>=1)&&(p.kp_proc.p_stat<=5)? statuses[p.kp_proc.p_stat-1]:"????");
+	ps->userName[sizeof(ps->userName)-1]='\0';
+
+#if __FreeBSD_version >= 500015
+        ps->userLoad = p.ki_pctcpu / 100;
+	ps->vmSize   = (p.ki_vmspace->vm_tsize +
+			p.ki_vmspace->vm_dsize +
+			p.ki_vmspace->vm_ssize) * getpagesize();
+	ps->vmRss    = p.ki_vmspace->vm_rssize * getpagesize();
+	strncpy(ps->name,p.ki_comm? p.ki_comm:"????",sizeof(ps->name));
+	strcpy(ps->status,(p.ki_stat>=1)&&(p.ki_stat<=5)? statuses[p.ki_stat-1]:"????");
+#else
+        ps->userLoad = p.kp_proc.p_pctcpu / 100;
+	ps->vmSize   = (p.kp_eproc.e_vm.vm_tsize +
+			p.kp_eproc.e_vm.vm_dsize +
+			p.kp_eproc.e_vm.vm_ssize) * getpagesize();
+	ps->vmRss    = p.kp_eproc.e_vm.vm_rssize * getpagesize();
+	strncpy(ps->name,p.kp_proc.p_comm? p.kp_proc.p_comm:"????",sizeof(ps->name));
+	strcpy(ps->status,(p.kp_proc.p_stat>=1)&&(p.kp_proc.p_stat<=5)? statuses[p.kp_proc.p_stat-1]:"????");
+#endif
 
         /* process command line */
         /*strncpy(ps->cmdline,p.kp_proc.p_args->ar_args,sizeof(ps->cmdline));
@@ -296,7 +314,11 @@
         sysctl(mib, 3, p, &len, NULL, 0);
 
 	for (num = 0; num < len / sizeof(struct kinfo_proc); num++)
+#if __FreeBSD_version >= 500015
+		updateProcess(p[num].ki_pid);
+#else
 		updateProcess(p[num].kp_proc.p_pid);
+#endif
 
 	cleanupProcessList();
 
