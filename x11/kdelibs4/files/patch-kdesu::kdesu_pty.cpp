--- kdesu/kdesu_pty.cpp.orig	Wed Apr 11 12:48:56 2001
+++ kdesu/kdesu_pty.cpp	Thu Jan 10 18:35:17 2002
@@ -101,13 +101,13 @@
 #elif defined(HAVE_OPENPTY)
     // 2: BSD interface
     // More prefered than the linux hacks
-    char name[10];
+    char name[30];
     int master_fd, slave_fd;
     if (openpty(&master_fd, &slave_fd, name, 0L, 0L) != -1)  {
 	ttyname = name;
 	name[5]='p';
 	ptyname = name;
-        //close(slave_fd); // We don't need this yet // Yes, we do.
+        close(slave_fd); // We don't need this yet // Yes, we do.
 	ptyfd = master_fd;
 	return ptyfd;
     }
