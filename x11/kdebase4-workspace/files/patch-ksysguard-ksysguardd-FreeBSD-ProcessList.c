--- ksysguard/ksysguardd/FreeBSD/ProcessList.c	Wed May  7 07:44:17 2003
+++ ksysguard/ksysguardd/FreeBSD/ProcessList.c	Wed Aug 27 18:51:18 2003
@@ -168,6 +168,8 @@
 	int mib[4];
 	struct kinfo_proc p;
 	size_t len;
+	size_t buflen = 256;
+	char buf[256];
 
 	if ((ps = findProcessInList(pid)) == 0)
 	{
@@ -239,10 +241,17 @@
 #endif
 
         /* process command line */
-	/* the following line causes segfaults on some FreeBSD systems... why?
-		strncpy(ps->cmdline, p.kp_proc.p_args->ar_args, sizeof(ps->cmdline) - 1);
-	*/
-	strcpy(ps->cmdline, "????");
+	/* do a sysctl to get the command line args. */
+
+	mib[0] = CTL_KERN;
+	mib[1] = KERN_PROC;
+	mib[2] = KERN_PROC_ARGS;
+	mib[3] = pid;
+	
+	if ((sysctl(mib, 4, buf, &buflen, 0, 0) == -1) || !buflen)
+ 		strcpy(ps->cmdline, "????"); 
+        else
+	        strncpy(ps->cmdline, buf, buflen - 1);
 
 	return (0);
 }
