--- gnome-session/gsm-dbus.c.orig	Mon Jan  8 17:32:28 2007
+++ gnome-session/gsm-dbus.c	Thu Jan 11 13:17:41 2007
@@ -281,6 +281,7 @@ start_parent (int address_fd, int pid_fd
   int exitstat;
   unsigned long tmp_num;
   ssize_t bytes;
+  int i;
 
   g_assert (child > 0);
 
@@ -326,14 +327,17 @@ start_parent (int address_fd, int pid_fd
   /*
    * Fetch dbus-daemon pid.
    */
-  bytes = read_line (pid_fd, pid_str, sizeof (pid_str));
-  if (bytes == -1 || bytes == 0)
+  for (i = 0; i < 2; i++)
     {
-      close (address_fd);
-      close (pid_fd);
-
-      g_printerr ("Failed to get dbus-daemon's pid\n");
-      return;
+      bytes = read_line (pid_fd, pid_str, sizeof (pid_str));
+      if (bytes == -1 || bytes == 0)
+        {
+          close (address_fd);
+          close (pid_fd);
+
+          g_printerr ("Failed to get dbus-daemon's pid\n");
+          return;
+        }
     }
 
   close (address_fd);
