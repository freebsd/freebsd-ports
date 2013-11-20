--- src/shell-global.c.orig	2012-10-03 22:10:22.000000000 +0000
+++ src/shell-global.c	2012-10-03 22:12:09.000000000 +0000
@@ -1255,9 +1255,9 @@
   GError *error = NULL;
   
   /* Linux specific (I think, anyways). */
-  if (!g_file_get_contents ("/proc/self/cmdline", &buf, &len, &error))
+  if (!g_file_get_contents ("/proc/curproc/cmdline", &buf, &len, &error))
     {
-      g_warning ("failed to get /proc/self/cmdline: %s", error->message);
+      g_warning ("failed to get /proc/curproc/cmdline: %s", error->message);
       return;
     }
       
