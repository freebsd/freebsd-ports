--- src/gnome-shell-plugin.c.orig	2010-06-06 22:53:13.000000000 +0200
+++ src/gnome-shell-plugin.c	2010-06-06 22:56:03.000000000 +0200
@@ -38,7 +38,6 @@
 #include <gjs/gjs.h>
 #include <girepository.h>
 #include <gmodule.h>
-#include <malloc.h>
 #include <stdlib.h>
 #include <string.h>
 
@@ -238,6 +237,7 @@
 malloc_statistics_callback (ShellPerfLog *perf_log,
                             gpointer      data)
 {
+#if defined(__linux__)
   struct mallinfo info = mallinfo ();
 
   shell_perf_log_update_statistic_i (perf_log,
@@ -249,6 +249,7 @@
   shell_perf_log_update_statistic_i (perf_log,
                                      "malloc.usedSize",
                                      info.uordblks);
+#endif
 }
 
 static void
