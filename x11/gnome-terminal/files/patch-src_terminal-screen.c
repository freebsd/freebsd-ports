--- src/terminal-screen.c.orig	2009-05-03 15:29:53.153369000 -0400
+++ src/terminal-screen.c	2009-05-03 15:30:35.000000000 -0400
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
@@ -1744,10 +1753,22 @@ terminal_screen_get_dynamic_icon_title (
 char*
 terminal_screen_get_current_dir (TerminalScreen *screen)
 {
+#ifndef __FreeBSD__
   static const char patterns[][18] = {
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
   TerminalScreenPrivate *priv = screen->priv;
   int fgpid;
   guint i;
@@ -1767,6 +1788,7 @@ terminal_screen_get_current_dir (Termina
   if (fgpid == -1)
     return g_strdup (priv->initial_working_directory);
 
+#ifndef __FreeBSD__
   /* Try to get the working directory using various OS-specific mechanisms */
   for (i = 0; i < G_N_ELEMENTS (patterns); ++i)
     {
@@ -1804,6 +1826,45 @@ terminal_screen_get_current_dir (Termina
             return working_dir;
         }
     }
+#else
+#if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+#ifndef HAVE_KINFO_GETFILE
+  name[0] = CTL_KERN;
+  name[1] = KERN_PROC;
+  name[2] = KERN_PROC_FILEDESC;
+  name[3] = fgpid;
+
+  if (sysctl (name, 4, NULL, &len, NULL, 0) < 0)
+    return g_strdup (priv->initial_working_directory);
+  freep = kif = g_malloc (len);
+  if (sysctl (name, 4, kif, &len, NULL, 0) < 0)
+    {
+      g_free (freep);
+      return g_strdup (priv->initial_working_directory);
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
+          g_free (freep);
+          return g_strdup (kif->kf_path);
+        }
+    }
+  g_free (freep);
+#endif /* __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104) */
+#endif /* __FreeBSD__ */
 
   return g_strdup (priv->initial_working_directory);
 }
