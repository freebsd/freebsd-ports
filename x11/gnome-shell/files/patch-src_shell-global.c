--- src/shell-global.c.orig	2014-03-19 18:15:45.680036087 +0000
+++ src/shell-global.c	2014-03-19 18:16:14.289034013 +0000
@@ -1145,6 +1145,12 @@
     g_warning ("failed to get command line args: %d", errno);
     return;
   }
+#elif defined __FreeBSD__
+  if (!g_file_get_contents ("/proc/curproc/cmdline", &buf, &len, &error))
+    {
+      g_warning ("failed to get /proc/curproc/cmdline: %s", error->message);
+      return;
+    }
 #else
   return;
 #endif
