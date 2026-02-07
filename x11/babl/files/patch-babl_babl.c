--- babl/babl.c.orig	2026-01-28 17:44:45 UTC
+++ babl/babl.c
@@ -24,6 +24,10 @@
 #include <dlfcn.h>
 #include <libgen.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/limits.h>
+#include <sys/param.h>
+#endif
 
 #include "config.h"
 #include "babl-internal.h"
@@ -456,7 +460,11 @@ _babl_find_relocatable_exe (void)
   char   *maps_line      = NULL;
   size_t  maps_line_size = 0;
 
+#if defined(__FreeBSD__)
+  sym_path = babl_strdup ("/proc/curproc/file");
+#else
   sym_path = babl_strdup ("/proc/self/exe");
+#endif
 
   while (1)
     {
@@ -520,7 +528,11 @@ _babl_find_relocatable_exe (void)
    * Read from /proc/self/maps as fallback.
    */
 
+#if defined(__FreeBSD__)
+  file = _babl_fopen ("/proc/curproc/map", "rb");
+#else
   file = _babl_fopen ("/proc/self/maps", "rb");
+#endif
 
   if (! file)
     babl_fatal ("Failed to read /proc/self/maps: %s", strerror (errno));
@@ -532,7 +544,11 @@ _babl_find_relocatable_exe (void)
       path = strchr (maps_line, '/');
 
       /* Sanity check. */
+#if defined(__FreeBSD__)
+      if (path && strstr (maps_line, " r-x "))
+#else
       if (path && strstr (maps_line, " r-xp "))
+#endif
         {
           /* We found the executable name. */
           path = babl_strdup (path);
