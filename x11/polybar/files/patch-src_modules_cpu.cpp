--- src/modules/cpu.cpp.orig	2023-11-05 22:37:13 UTC
+++ src/modules/cpu.cpp
@@ -2,6 +2,11 @@
 
 #include <fstream>
 #include <istream>
+#ifdef __FreeBSD__
+  #include <sys/types.h>
+  #include <sys/resource.h>
+  #include <sys/sysctl.h>
+#endif
 
 #include "drawtypes/label.hpp"
 #include "drawtypes/progressbar.hpp"
@@ -129,6 +134,41 @@ namespace modules {
     m_cputimes.clear();
 
     try {
+#ifdef __FreeBSD__
+      // Get number of CPUs
+      // ToDo: No need to do this on every invocation.
+      int ncpu = -1;
+      std::size_t sz = sizeof(ncpu);
+      if (sysctlbyname("hw.ncpu", &ncpu, &sz, nullptr, 0) != 0) {
+        m_log.err("Failed to query sysctl 'hw.ncpu' (errno: %s)", strerror(errno));
+        return false;
+      }
+      if (ncpu < 1) {
+        m_log.err("Failed to determine number of CPUs.");
+        return false;
+      }
+
+      // Query 'kern.cp_time'
+      long cpu_stat[CPUSTATES];
+      sz = sizeof(cpu_stat);
+      if (sysctlbyname("kern.cp_time", cpu_stat, &sz, nullptr, 0) != 0) {
+        m_log.err("Failed to query sysctl 'kern.cp_time' (errno: %s)", strerror(errno));
+        return false;
+      }
+
+      // Parse
+      static std::size_t field_offset = sizeof(*cpu_stat) + ncpu;
+      for (std::size_t i = 0; i < ncpu; i++) {
+        m_cputimes.emplace_back(new cpu_time);
+        m_cputimes.back()->user = cpu_stat[CP_USER];
+        m_cputimes.back()->nice = cpu_stat[CP_NICE];
+        m_cputimes.back()->system = cpu_stat[CP_SYS];
+        m_cputimes.back()->steal = cpu_stat[CP_INTR];   // Note: This is technically the reported "interrupt" time
+        m_cputimes.back()->idle = cpu_stat[CP_IDLE];
+        m_cputimes.back()->total = m_cputimes.back()->user + m_cputimes.back()->nice + m_cputimes.back()->system +
+                                   m_cputimes.back()->idle + m_cputimes.back()->steal;
+      }
+#else
       std::ifstream in(PATH_CPU_INFO);
       string str;
 
@@ -149,6 +189,7 @@ namespace modules {
         m_cputimes.back()->total = m_cputimes.back()->user + m_cputimes.back()->nice + m_cputimes.back()->system +
                                    m_cputimes.back()->idle + m_cputimes.back()->steal;
       }
+#endif
     } catch (const std::ios_base::failure& e) {
       m_log.err("Failed to read CPU values (what: %s)", e.what());
     }
