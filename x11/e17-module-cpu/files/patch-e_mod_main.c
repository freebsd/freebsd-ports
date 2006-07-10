--- e_mod_main.c.orig	Sun Jul  9 14:15:46 2006
+++ e_mod_main.c	Sun Jul  9 15:58:09 2006
@@ -3,6 +3,12 @@
 #include "e_mod_config.h"
 #include "config.h"
 
+#if defined(__FreeBSD__)
+# include <sys/types.h>
+# include <sys/sysctl.h>
+# include <sys/resource.h>
+#endif
+
 static Cpu *_cpu_init(E_Module *m);
 static void _cpu_shutdown(Cpu *n);
 static void _cpu_config_menu_new(Cpu *n);
@@ -460,31 +466,66 @@
    FILE *f;
    int cpu = -1;
 
+#if defined(__FreeBSD__)
+   cpu = 1; /* We can't retrive per-cpu statistics, so we'll assume UP arch*/
+#else
    if (!(f = fopen("/proc/stat", "r")))
       return -1;
 
    while (fscanf(f, "cp%s %*u %*u %*u %*u %*u %*u %*u %*u\n", (char *)&tmp) == 1)
       cpu++;
-
    fclose(f);
+#endif
+
    return cpu;
 }
 
 static void
 _cpu_face_get_load(Cpu_Face *cf)
 {
+   int cpu_count;
+   Edje_Message_Float msg;
+#if defined(__FreeBSD__)
+   long cp_time[CPUSTATES];
+   static long old_used, old_tot;
+   long new_used, new_tot;
+   size_t len;
+#else
    static unsigned long old_u[4], old_n[4], old_s[4], old_i[4], old_wa[4], old_hi[4], old_si[4];
    unsigned long new_u, new_n, new_s, new_i, new_wa = 0, new_hi = 0, new_si = 0, ticks_past;
    int tmp_u, tmp_n, tmp_s, tmp_i;
    char dummy[16];
    FILE *stat;
-   int cpu_count;
-   Edje_Message_Float msg;
+#endif
 
    cpu_count = _cpu_face_get_cpu_count(cf);
    if (cpu_count == -1)
       return;
 
+#if defined(__FreeBSD__)
+   len = sizeof(cp_time);
+
+   if (sysctlbyname("kern.cp_time", &cp_time, &len, NULL, 0) < 0) {
+	warn("sysctl()");
+	return;
+   }
+
+   new_used = cp_time[CP_USER] + cp_time[CP_NICE] + cp_time[CP_SYS];
+   new_tot = new_used + cp_time[CP_IDLE];
+
+   if (new_tot == old_tot)
+	msg.val = 0;
+   else
+	msg.val = 100 * (float)(new_used - old_used) / (float)(new_tot - old_tot);
+
+   cpu_stats[0] = msg.val;
+   edje_object_message_send(cf->cpu_obj, EDJE_MESSAGE_FLOAT, 0, &msg);
+
+   old_tot = new_tot;
+   old_used = new_used;
+
+#else
+
    if (!(stat = fopen("/proc/stat", "r")))
       return;
 
@@ -537,6 +578,7 @@
         i++;
      }
    fclose(stat);
+#endif
 }
 
 static void
