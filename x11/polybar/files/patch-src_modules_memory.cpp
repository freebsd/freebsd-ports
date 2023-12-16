--- src/modules/memory.cpp.orig	2023-11-05 22:37:13 UTC
+++ src/modules/memory.cpp
@@ -1,6 +1,10 @@
 #include <fstream>
 #include <iomanip>
 #include <istream>
+#ifdef __FreeBSD__
+  #include <sys/types.h>
+  #include <sys/sysctl.h>
+#endif
 
 #include "drawtypes/label.hpp"
 #include "drawtypes/progressbar.hpp"
@@ -64,6 +68,25 @@ namespace modules {
     unsigned long long kb_swap_free{0ULL};
 
     try {
+#ifdef __FreeBSD__
+      std::size_t sz;
+
+      // Total
+      sz = sizeof(kb_total);
+      if (sysctlbyname("hw.physmem", &kb_total, &sz, nullptr, 0) != 0) {
+        m_log.err("Failed to query sysctl 'hw.physmem' (errno: %s)", strerror(errno));
+        return false;
+      }
+      kb_total /= 1024;
+
+      // Available
+      sz = sizeof(kb_avail);
+      if (sysctlbyname("hw.usermem", &kb_avail, &sz, nullptr, 0) != 0) {
+        m_log.err("Failed to query sysctl 'hw.usermem' (errno: %s)", strerror(errno));
+        return false;
+      }
+      kb_avail /= 1024;
+#else
       std::ifstream meminfo(PATH_MEMORY_INFO);
       std::map<std::string, unsigned long long int> parsed;
 
@@ -92,6 +115,7 @@ namespace modules {
         // old kernel; give a best-effort approximation of available memory
         kb_avail = parsed["MemFree"] + parsed["Buffers"] + parsed["Cached"] + parsed["SReclaimable"] - parsed["Shmem"];
       }
+#endif
     } catch (const std::exception& err) {
       m_log.err("Failed to read memory values (what: %s)", err.what());
     }
