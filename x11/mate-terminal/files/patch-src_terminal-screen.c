--- src/terminal-screen.c.orig	2012-07-27 16:58:59.000000000 -0500
+++ src/terminal-screen.c	2012-07-27 17:03:08.000000000 -0500
@@ -18,6 +18,15 @@
 
 #include <config.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/param.h>
+#include <sys/user.h>
+#ifdef HAVE_KINFO_GETFILE
+#include <libutil.h>
+#endif
+#endif
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -190,16 +199,29 @@
 static char *
 cwd_of_pid (int pid)
 {
+#ifndef __FreeBSD__
 	static const char patterns[][18] =
 	{
 		"/proc/%d/cwd",         /* Linux */
 		"/proc/%d/path/cwd",    /* Solaris >= 10 */
 	};
+#else
+#if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+  struct kinfo_file *freep, *kif;
+#ifndef HAVE_KINFO_GETFILE
+  size_t len;
+  int name[4];
+#else
+  int cnt;
+#endif /* HAVE_KINFO_GETFILE */
+#endif /* __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104) */
+#endif /* __FreeBSD__ */
 	guint i;
 
 	if (pid == -1)
 		return NULL;
 
+#ifndef __FreeBSD__
 	/* Try to get the working directory using various OS-specific mechanisms */
 	for (i = 0; i < G_N_ELEMENTS (patterns); ++i)
 	{
@@ -237,6 +259,49 @@
 				return working_dir;
 		}
 	}
+#else
+  int fgpid = pid;
+#if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+#ifndef HAVE_KINFO_GETFILE
+  name[0] = CTL_KERN;
+  name[1] = KERN_PROC;
+  name[2] = KERN_PROC_FILEDESC;
+  name[3] = fgpid;
+
+  if (sysctl (name, 4, NULL, &len, NULL, 0) < 0)
+    return NULL;
+  freep = kif = g_malloc (len);
+  if (sysctl (name, 4, kif, &len, NULL, 0) < 0)
+    {
+      g_free (freep);
+      return NULL;
+    }
+#else
+  freep = kinfo_getfile (fgpid, &cnt);
+#endif /* HAVE_KINFO_GETFILE */
+
+#ifndef HAVE_KINFO_GETFILE
+  for (i = 0; i < len / sizeof (*kif); i++, kif++)
+    {
+      if (kif->kf_structsize != sizeof (*kif))
+        continue;
+#else
+  for (i = 0; i < cnt; i++)
+    {
+      kif = &freep[i];
+#endif /* HAVE_KINFO_GETFILE */
+      if (kif->kf_fd == KF_FD_TYPE_CWD)
+        {
+          char *working_dir;
+
+          working_dir = g_strdup (kif->kf_path);
+          g_free (freep);
+          return working_dir;
+        }
+    }
+  g_free (freep);
+#endif /* __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104) */
+#endif /* __FreeBSD__ */
 
 	return NULL;
 }
