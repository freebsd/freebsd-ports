--- ./plugins/mem/mem.c.orig	2010-04-28 04:39:31.000000000 -0700
+++ ./plugins/mem/mem.c	2010-11-17 11:11:10.000000000 -0800
@@ -1,3 +1,6 @@
+/* vim:set ts=4 
+ * Code for FreeBSD added by Charlie Kester <corky1951@comcast.net>
+ */
 #include <time.h>
 #include <sys/time.h>
 #include <sys/types.h>
@@ -6,6 +9,11 @@
 #include <string.h>
 #include <strings.h>
 
+#if defined __FreeBSD__
+#include <sys/sysctl.h>
+#include <sys/resource.h>
+#include <vm/vm_param.h>
+#endif
 
 #include "panel.h"
 #include "misc.h"
@@ -112,11 +120,104 @@
     stats.swap.total = mt[MT_SwapTotal].val;
     stats.swap.used = mt[MT_SwapTotal].val - mt[MT_SwapFree].val;
 }
+#elif defined __FreeBSD__
+
+static void
+mem_usage()
+{
+	static unsigned long realmem;
+	static int	mib_freecount[4], mib_cachecount[4], mib_inactivecount[4],
+			mib_swapinfo[16], init = 0, pagesize;
+	static u_int	mib_free_size, mib_cache_size, mib_inactive_size,
+			mib_swapinfo_size;
+	struct xswdev	xsw;
+	long		scale;
+	size_t		len;
+	int		freecount , cachecount, inactivecount, n;
+
+
+	if (init == 0) {
+		//initialize meminfo
+		len = sizeof(unsigned long);
+		if (sysctlbyname("hw.realmem", &realmem, &len, NULL, 0) == -1) {
+			DBG("Can't get hw.realmem");
+			return;
+		}
+		len = sizeof(int);
+		if (sysctlbyname("vm.stats.vm.v_page_size", &pagesize, &len, NULL, 0) == -1) {
+			DBG("Can't get vm page size");
+			return;
+		}
+		mib_free_size = 4;
+		if (sysctlnametomib("vm.stats.vm.v_free_count", mib_freecount, &mib_free_size) == -1) {
+			DBG("Can't get mib for mem free stat");
+			return;
+		}
+		mib_cache_size = 4;
+		if (sysctlnametomib("vm.stats.vm.v_cache_count", mib_cachecount, &len) == -1) {
+			DBG("Can't get mib for cached mem stat");
+			return;
+		}
+		mib_inactive_size = 4;
+		if (sysctlnametomib("vm.stats.vm.v_inactive_count", mib_inactivecount, &mib_inactive_size) == -1) {
+			DBG("Can't get mib for mem inactive stat");
+			return;
+		}
+		//initialize swapinfo
+		mib_swapinfo_size = sizeof(mib_swapinfo) / sizeof(mib_swapinfo[0]);
+		if (sysctlnametomib("vm.swap_info", mib_swapinfo, &mib_swapinfo_size) == -1) {
+			DBG("Can't get mib for swapinfo");
+			return;
+		}
+		init = 1;
+	}
+	//get current meminfo
+	len = sizeof(int);
+	if (sysctl(mib_freecount, mib_free_size, &freecount, &len, NULL, 0) == -1) {
+		DBG("Couldn't get mem free stat");
+		return;
+	}
+	if (sysctl(mib_cachecount, mib_cache_size, &cachecount, &len, NULL, 0) == -1) {
+		DBG("Couldn't get cached mem stat");
+		return;
+	}
+	if (sysctl(mib_inactivecount, mib_inactive_size, &inactivecount, &len, NULL, 0) == -1) {
+		DBG("Couldn't get inactive mem stat");
+		return;
+	}
+	//save in kilobytes(same as /proc/meminfo)
+	stats.mem.total = realmem / 1024;
+	//For FreeBSD, there doesn't seem to be any firm consensus on the meaning of "memory used".
+	//Some utils count only wired memory as used, while others also include active and inactive memory.
+	//
+	//The 'top' utility doesn't bother to calculate "memory used" at all, but simply reports the values for 
+	//active, inactive, wired, cached, and free.  Unfortunately we can't follow that sensible approach here.
+	//
+	//The calculation below reflects the interpretation used by the sysinfo and freebsd_memory utils.
+	stats.mem.used = (realmem - pagesize * (freecount + cachecount + inactivecount)) / 1024;
+
+	//get swapinfo
+	scale = pagesize / 1024;
+	for (n = 0;; ++n) {
+		mib_swapinfo[mib_swapinfo_size] = n;
+		len = sizeof xsw;
+		if (sysctl(mib_swapinfo, mib_swapinfo_size + 1, &xsw, &len, 0, 0) == -1) {
+			// not necessarily an error!
+			break;
+		}
+		if (xsw.xsw_version != XSWDEV_VERSION) {
+			DBG("XSW version mismatch");
+			break;
+		}
+		stats.swap.total += xsw.xsw_nblks * scale;
+		stats.swap.used += xsw.xsw_used * scale;
+	}
+}
 #else
 static void
 mem_usage()
 {
-   
+
 }
 #endif
 
