--- src/wdm/loghelpers.c.orig	Sun Jun  1 17:00:09 2003
+++ src/wdm/loghelpers.c	Sun Jun  1 23:30:40 2003
@@ -26,6 +26,21 @@
 #include <sys/wait.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+static char *
+wstrndup(const char *src, size_t size)
+{
+	char *dst;
+
+	dst = malloc(size + 1);
+	if (dst == NULL)
+		return (NULL);
+	dst[size] = '\0';
+	strncpy(dst, src, size);
+	return (dst);
+}
+#endif
+
 /*
  * Function that treats buffer as set of lines separated with '\n'
  * These lines will be directed to WDMLogMessage function with
