--- ./src/log.c.orig	2013-03-20 15:28:14.746383400 +0100
+++ ./src/log.c	2013-03-20 18:27:56.885378021 +0100
@@ -81,11 +81,11 @@
 void init_logging(void) {
     if (!errorfilename) {
         if (!(errorfilename = get_process_filename("errorlog")))
-            ELOG("Could not initialize errorlog\n");
+            fprintf(stderr, "Could not initialize errorlog\n");
         else {
             errorfile = fopen(errorfilename, "w");
             if (fcntl(fileno(errorfile), F_SETFD, FD_CLOEXEC)) {
-                ELOG("Could not set close-on-exec flag\n");
+                fprintf(stderr, "Could not set close-on-exec flag\n");
             }
         }
     }
@@ -107,25 +107,28 @@
                                         sysconf(_SC_PAGESIZE);
 #endif
         logbuffer_size = min(physical_mem_bytes * 0.01, shmlog_size);
-        sasprintf(&shmlogname, "/i3-log-%d", getpid());
+#if defined(__FreeBSD__)
+	asprintf(&shmlogname, "/tmp/i3-log-%d", getpid());
+#else
+        asprintf(&shmlogname, "/i3-log-%d", getpid());
+#endif
         logbuffer_shm = shm_open(shmlogname, O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
         if (logbuffer_shm == -1) {
-            ELOG("Could not shm_open SHM segment for the i3 log: %s\n", strerror(errno));
+            fprintf(stderr, "Could not shm_open SHM segment for the i3 log: %s\n", strerror(errno));
             return;
         }
-
         if (ftruncate(logbuffer_shm, logbuffer_size) == -1) {
             close(logbuffer_shm);
-            shm_unlink("/i3-log-");
-            ELOG("Could not ftruncate SHM segment for the i3 log: %s\n", strerror(errno));
+            shm_unlink(shmlogname);
+            fprintf(stderr, "Could not ftruncate SHM segment for the i3 log: %s\n", strerror(errno));
             return;
         }
 
         logbuffer = mmap(NULL, logbuffer_size, PROT_READ | PROT_WRITE, MAP_SHARED, logbuffer_shm, 0);
         if (logbuffer == MAP_FAILED) {
             close(logbuffer_shm);
-            shm_unlink("/i3-log-");
-            ELOG("Could not mmap SHM segment for the i3 log: %s\n", strerror(errno));
+            shm_unlink(shmlogname);
+            fprintf(stderr, "Could not mmap SHM segment for the i3 log: %s\n", strerror(errno));
             logbuffer = NULL;
             return;
         }
@@ -138,13 +141,14 @@
         pthread_condattr_t cond_attr;
         pthread_condattr_init(&cond_attr);
         if (pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED) != 0)
-            ELOG("pthread_condattr_setpshared() failed, i3-dump-log -f will not work!\n");
+            fprintf(stderr, "pthread_condattr_setpshared() failed, i3-dump-log -f will not work!\n");
         pthread_cond_init(&(header->condvar), &cond_attr);
 
         logwalk = logbuffer + sizeof(i3_shmlog_header);
         loglastwrap = logbuffer + logbuffer_size;
         store_log_markers();
     }
+
     atexit(purge_zerobyte_logfile);
 }
 
