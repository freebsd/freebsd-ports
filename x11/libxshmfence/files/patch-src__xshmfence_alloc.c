--- src/xshmfence_alloc.c.orig	2015-03-04 15:28:23 UTC
+++ src/xshmfence_alloc.c
@@ -79,7 +79,11 @@ xshmfence_alloc_shm(void)
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
