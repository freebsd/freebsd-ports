--- src/xshmfence_alloc.c.orig	2013-11-20 17:13:08.000000000 -0500
+++ src/xshmfence_alloc.c	2014-07-08 16:39:18.000000000 -0400
@@ -39,10 +39,14 @@
 xshmfence_alloc_shm(void)
 {
 	char	template[] = SHMDIR "/shmfd-XXXXXX";
-	int	fd;
+	int	fd = -1;
 
-#ifdef O_TMPFILE
+#if defined(O_CLOEXEC)
+#if defined(HAVE_MKOSTEMP)
+	fd = mkostemp(template, O_CLOEXEC);
+#elif defined(O_TMPFILE)
 	fd = open(SHMDIR, O_TMPFILE|O_RDWR|O_CLOEXEC|O_EXCL, 0666);
+#endif
 	if (fd < 0)
 #endif
         {
