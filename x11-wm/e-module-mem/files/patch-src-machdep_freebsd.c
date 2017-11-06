--- src/machdep_freebsd.c.orig	2014-09-23 14:36:23 UTC
+++ src/machdep_freebsd.c
@@ -12,6 +12,8 @@
 
 #define GETSYSCTL(name, var)    getsysctl(name, &(var), sizeof (var))
 
+#define PAGES_PER_MEG ((1024 * 1024) / getpagesize())
+
 static int
 getsysctl (char *name, void *ptr, size_t len)
 {
@@ -32,7 +34,6 @@ getsysctl (char *name, void *ptr, size_t
 static int
 swapinfo (int *total, int *used)
 {
-  int pagesize = getpagesize ();
   size_t mibsize, size;
   struct xswdev xsw;
   int mib[16], n;
@@ -61,8 +62,8 @@ swapinfo (int *total, int *used)
 	  return 1;
 	}
 
-      tmp_total = (long long) xsw.xsw_nblks * pagesize;
-      tmp_used = (long long) xsw.xsw_used * pagesize;
+      tmp_total = xsw.xsw_nblks / PAGES_PER_MEG;
+      tmp_used = xsw.xsw_used / PAGES_PER_MEG;
       *total += tmp_total;
       *used += tmp_used;
     }
@@ -82,8 +83,6 @@ _mem_get_values (ci, phys_used, sw_used,
 {
   int total_pages, inactive_pages, free_pages;
 
-  int pagesize = getpagesize ();
-
   if (GETSYSCTL ("vm.stats.vm.v_page_count", total_pages))
     {
       warnx ("can't read sysctl \"vm.stats.vm.v_page_count\"");
@@ -102,8 +101,8 @@ _mem_get_values (ci, phys_used, sw_used,
       return;
     }
 
-  *phys_total = (total_pages * pagesize) >> 10;
-  *phys_used = ((total_pages - free_pages - inactive_pages) * pagesize) >> 10;
+  *phys_total = total_pages / PAGES_PER_MEG;
+  *phys_used = (total_pages - free_pages - inactive_pages) / PAGES_PER_MEG;
 
   if ((swapinfo (sw_total, sw_used)) != 0)
     {
