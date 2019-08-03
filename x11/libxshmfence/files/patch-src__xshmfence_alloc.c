--- src/xshmfence_alloc.c.orig	2015-03-04 15:28:23 UTC
+++ src/xshmfence_alloc.c
@@ -73,13 +73,21 @@ xshmfence_alloc_shm(void)
 	fd = memfd_create("xshmfence", MFD_CLOEXEC|MFD_ALLOW_SEALING);
 	if (fd < 0)
 #endif
+#ifdef SHM_ANON
+	fd = shm_open(SHM_ANON, O_RDWR|O_CLOEXEC, 0600);
+	if (fd < 0)
+#endif
 	{
 #ifdef O_TMPFILE
 		fd = open(SHMDIR, O_TMPFILE|O_RDWR|O_CLOEXEC|O_EXCL, 0666);
 		if (fd < 0)
 #endif
 		{
+#ifdef HAVE_MKOSTEMP
+			fd = mkostemp(template, O_CLOEXEC);
+#else
 			fd = mkstemp(template);
+#endif
 			if (fd < 0)
 				return fd;
 			unlink(template);
