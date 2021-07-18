--- src/xshmfence_alloc.c.orig	2018-02-26 17:26:59 UTC
+++ src/xshmfence_alloc.c
@@ -48,9 +48,13 @@ static int memfd_create(const char *name,
 #include <sys/memfd.h>
 #else
 /* flags for memfd_create(2) (unsigned int) */
+#ifndef MFD_CLOEXEC
 #define MFD_CLOEXEC		0x0001U
+#endif
+#ifndef MFD_ALLOW_SEALING
 #define MFD_ALLOW_SEALING	0x0002U
 #endif
+#endif
 
 #endif
 
@@ -73,13 +77,21 @@ xshmfence_alloc_shm(void)
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
