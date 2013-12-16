--- src/xshmfence_alloc.c	2013-11-20 17:13:08.000000000 -0500
+++ src/xshmfence_alloc.c	2013-12-09 16:06:17.000000000 -0500
@@ -41,11 +41,15 @@
 	char	template[] = SHMDIR "/shmfd-XXXXXX";
 	int	fd;
 
-#ifdef O_TMPFILE
+#if defined(O_CLOEXEC)
+#if defined(HAVE_MKOSTEMP)
+	fd = mkostemp(template, O_CLOEXEC);
+#elif defined(O_TMPFILE)
 	fd = open(SHMDIR, O_TMPFILE|O_RDWR|O_CLOEXEC|O_EXCL, 0666);
-	if (fd < 0)
 #endif
+	if (fd < 0)
         {
+#endif
             fd = mkstemp(template);
             if (fd < 0)
 		return fd;
