--- src/xfce-taskmanager-freebsd.c.orig	Thu Mar  1 16:17:09 2007
+++ src/xfce-taskmanager-freebsd.c	Thu Mar  1 16:18:01 2007
@@ -0,0 +1,172 @@
+/*
+ Copyright (c) 2006 Oliver Lehmann <oliver@FreeBSD.org>
+ All rights reserved.
+
+ Redistribution and use in source and binary forms, with or without
+ modification, are permitted provided that the following conditions
+ are met:
+ 1. Redistributions of source code must retain the above copyright
+       notice, this list of conditions and the following disclaimer
+ 2. Redistributions in binary form must reproduce the above copyright
+       notice, this list of conditions and the following disclaimer in the
+       documentation and/or other materials provided with the distribution.
+
+ THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
+ ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
+ FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ SUCH DAMAGE.
+
+ $Id: index.php,v 1.24 2006/12/21 23:09:25 olivleh1 Exp $
+*/
+
+
+#include "xfce-taskmanager-freebsd.h"
+
+#define	fxtofl(fixpt)	((double)(fixpt) / fscale)
+
+struct task get_task_details(struct kinfo_proc *kp)
+{
+	struct task task;
+	size_t	size;
+	fixpt_t	ccpu;
+	long	fracmem;
+	int	pagesize, flag, sflag, tdflags, fscale;
+	char	*cp;
+	char	buf[16];
+
+	task.pid = -1;
+	task.checked = FALSE;
+	
+	size = sizeof(ccpu);
+	if (sysctlbyname("kern.ccpu", &ccpu, &size, NULL, 0) == -1)
+		return (task);
+	size = sizeof(fscale);
+	if (sysctlbyname("kern.fscale", &fscale, &size, NULL, 0) == -1)
+		return (task);
+	size = sizeof(pagesize);
+	if (sysctlbyname("hw.pagesize",&pagesize,&size,NULL,0) == -1)
+		return (task);
+
+	task.pid = kp->ki_pid;
+	task.ppid = kp->ki_ppid;
+	task.size = (kp->ki_size/1024);
+	task.rss = (kp->ki_rssize*pagesize)/1024;
+	task.time_percentage = 100.0 * fxtofl(kp->ki_pctcpu) / (1.0 - exp(kp->ki_swtime * log(fxtofl(ccpu))));
+	task.uid = kp->ki_uid;
+	g_strlcpy(task.uname, user_from_uid(kp->ki_uid, 0), sizeof task.uname);
+		
+
+	flag = kp->ki_flag;
+	sflag = kp->ki_sflag;
+	tdflags = kp->ki_tdflags;
+	cp = buf;
+
+	switch (kp->ki_stat) {
+
+	case SSTOP:
+		*cp = 'T';
+		break;
+
+	case SSLEEP:
+		if (tdflags & TDF_SINTR)
+			*cp = kp->ki_slptime >= MAXSLP ? 'I' : 'S';
+		else
+			*cp = 'D';
+		break;
+
+	case SRUN:
+	case SIDL:
+		*cp = 'R';
+		break;
+
+	case SWAIT:
+		*cp = 'W';
+		break;
+
+	case SLOCK:
+		*cp = 'L';
+		break;
+
+	case SZOMB:
+		*cp = 'Z';
+		break;
+
+	default:
+		*cp = '?';
+	}
+	cp++;
+	if (!(sflag & PS_INMEM))
+		*cp++ = 'W';
+	if (kp->ki_nice < NZERO)
+		*cp++ = '<';
+	else if (kp->ki_nice > NZERO)
+		*cp++ = 'N';
+	if (flag & P_TRACED)
+		*cp++ = 'X';
+	if (flag & P_WEXIT && kp->ki_stat != SZOMB)
+		*cp++ = 'E';
+	if (flag & P_PPWAIT)
+		*cp++ = 'V';
+	if ((flag & P_SYSTEM) || kp->ki_lock > 0)
+		*cp++ = 'L';
+	if (kp->ki_kiflag & KI_SLEADER)
+		*cp++ = 's';
+	if ((flag & P_CONTROLT) && kp->ki_pgid == kp->ki_tpgid)
+		*cp++ = '+';
+	if (flag & P_JAILED)
+		*cp++ = 'J';
+	*cp = '\0';
+	
+	g_strlcpy(task.state, buf, sizeof task.state);
+	g_strlcpy(task.name, kp->ki_comm, sizeof task.name);
+
+	if(g_str_has_suffix(task.name, ")"))
+		*g_strrstr(task.name, ")") = '\0';
+
+	return task;
+}
+
+GArray *get_task_list()
+{
+	GArray *task_list;
+	struct task task;
+	int nentries, what, flag, i;
+	struct kinfo_proc *kp;
+	const char *nlistf, *memf;
+	static kvm_t	*kd;
+	char *state;
+	char errbuf[_POSIX2_LINE_MAX];
+
+	nentries = -1;
+	memf = nlistf = _PATH_DEVNULL;
+	kd = kvm_openfiles(nlistf, memf, NULL, O_RDONLY, errbuf);
+	if (kd == 0) {
+		fprintf(stderr, "Error: %s\n", errbuf);
+		return NULL;
+	}
+	kp = kvm_getprocs(kd, KERN_PROC_PROC, 0, &nentries);
+	if ((kp == NULL && nentries > 0) || (kp != NULL && nentries < 0)) {
+		fprintf(stderr, "Error: %s\n", kvm_geterr(kd));
+		return NULL;
+	}
+
+	task_list = g_array_new (FALSE, FALSE, sizeof (struct task));
+	if (nentries > 0) {
+	
+		for (i = nentries; --i >= 0; ++kp) {
+			struct task task = get_task_details(kp);		
+			if(task.pid != -1)
+				g_array_append_val(task_list, task);
+		}
+
+	}
+	kvm_close(kd);
+	return task_list;
+}
