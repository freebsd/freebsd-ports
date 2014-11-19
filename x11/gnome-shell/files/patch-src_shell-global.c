--- src/shell-global.c.orig	2014-10-13 22:57:06.000000000 +0200
+++ src/shell-global.c	2014-10-20 15:37:28.727759860 +0200
@@ -1240,13 +1240,13 @@
 {
   GPtrArray *arr;
   gsize len;
-
-#if defined __linux__
   char *buf;
   char *buf_p;
   char *buf_end;
   GError *error = NULL;
 
+#if defined __linux__
+
   if (!g_file_get_contents ("/proc/self/cmdline", &buf, &len, &error))
     {
       g_warning ("failed to get /proc/self/cmdline: %s", error->message);
@@ -1281,6 +1281,12 @@
   }
 
   g_ptr_array_add (arr, NULL);
+#elif defined __FreeBSD__
+  if (!g_file_get_contents ("/proc/curproc/cmdline", &buf, &len, &error))
+    {
+      g_warning ("failed to get /proc/curproc/cmdline: %s", error->message);
+      return;
+    }
 #else
   return;
 #endif
