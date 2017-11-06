--- src/task-manager-freebsd.c.orig	2017-01-23 06:53:01 UTC
+++ src/task-manager-freebsd.c
@@ -26,11 +26,11 @@
 
 #include "task-manager.h"
 
-gulong
+guint64
 get_mem_by_bytes (const gchar *name)
 {
-	gulong buf;
-	gsize len = sizeof (gulong);
+	guint64 buf = 0;
+	gsize len = sizeof (buf);
 
 	if (sysctlbyname (name, &buf, &len, NULL, 0) < 0)
 		return 0;
@@ -41,13 +41,13 @@ get_mem_by_bytes (const gchar *name)
 guint64
 get_mem_by_pages (const gchar *name)
 {
-	gulong res;
+	guint64 res;
 
 	res = get_mem_by_bytes (name);
 	if (res > 0)
 		res = res * getpagesize ();
 
-	return (guint64) res;
+	return res;
 }
 
 gboolean
@@ -55,10 +55,10 @@ get_memory_usage (guint64 *memory_total,
 {
 	/* Get memory usage */
 	{
-		*memory_total = (guint64) get_mem_by_bytes ("hw.physmem");;
+		*memory_total = get_mem_by_bytes ("hw.physmem");;
 		*memory_free = get_mem_by_pages ("vm.stats.vm.v_free_count");
 		*memory_cache = get_mem_by_pages ("vm.stats.vm.v_inactive_count");
-		*memory_buffers = (guint64) get_mem_by_bytes ("vfs.bufspace");
+		*memory_buffers = get_mem_by_bytes ("vfs.bufspace");
 	}
 
 	/* Get swap usage */
