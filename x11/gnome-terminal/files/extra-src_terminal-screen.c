--- src/terminal-screen.c.orig	2014-09-23 20:15:23.000000000 +0200
+++ src/terminal-screen.c	2014-11-09 20:19:35.759291981 +0100
@@ -1192,7 +1192,21 @@
       for (j = 0; j < n_fds; j++) {
         if (fds[j] == target_fd) {
           do {
+#if defined(F_DUPFD_CLOEXEC)
             fd = fcntl (fds[j], F_DUPFD_CLOEXEC, 3);
+#else
+            fd = fcntl (fds[j], F_DUPFD, 3);
+            int flags = fcntl (fd, F_GETFD);
+            if (flags ==  -1)
+            {
+              //errror
+            }
+            flags |= FD_CLOEXEC;
+            if (fcntl (fd, F_SETFD, FD_CLOEXEC) == -1)
+            {
+              //error
+            }
+#endif
           } while (fd == -1 && errno == EINTR);
           if (fd == -1)
             _exit (127);
