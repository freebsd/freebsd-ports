--- src/xshmfence_alloc.c.orig	2015-03-04 15:28:23 UTC
+++ src/xshmfence_alloc.c
@@ -67,15 +67,19 @@ int
 xshmfence_alloc_shm(void)
 {
 	char	template[] = SHMDIR "/shmfd-XXXXXX";
-	int	fd;
+	int	fd = -1;
 
 #if HAVE_MEMFD_CREATE
 	fd = memfd_create("xshmfence", MFD_CLOEXEC|MFD_ALLOW_SEALING);
 	if (fd < 0)
 #endif
 	{
-#ifdef O_TMPFILE
+#if defined(O_CLOEXEC)
+#if defined(HAVE_MKOSTEMP)
+		fd = mkostemp(template, O_CLOEXEC);
+#elif defined(O_TMPFILE)
 		fd = open(SHMDIR, O_TMPFILE|O_RDWR|O_CLOEXEC|O_EXCL, 0666);
+#endif
 		if (fd < 0)
 #endif
 		{
