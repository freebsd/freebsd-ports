--- ksysguard/ksysguardd/FreeBSD/ProcessList.c.orig	Sun Feb  9 18:54:36 2003
+++ ksysguard/ksysguardd/FreeBSD/ProcessList.c	Sun Feb  9 18:54:51 2003
@@ -224,10 +224,8 @@
 
 #if __FreeBSD_version >= 500015
         ps->userLoad = p.ki_pctcpu / 100;
-	ps->vmSize   = (p.ki_vmspace->vm_tsize +
-			p.ki_vmspace->vm_dsize +
-			p.ki_vmspace->vm_ssize) * getpagesize();
-	ps->vmRss    = p.ki_vmspace->vm_rssize * getpagesize();
+	ps->vmSize   = p.ki_size;
+	ps->vmRss    = p.ki_rssize;
 	strncpy(ps->name,p.ki_comm? p.ki_comm:"????",sizeof(ps->name));
 	strcpy(ps->status,(p.ki_stat>=1)&&(p.ki_stat<=5)? statuses[p.ki_stat-1]:"????");
 #else
