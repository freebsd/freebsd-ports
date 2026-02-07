--- cmd/util.c.orig	2007-11-16 13:59:15 UTC
+++ cmd/util.c
@@ -9,6 +9,10 @@
 #include <util.h>
 #include <fmt.h>
 
+char *argv0;
+void *__p;
+int __i;
+
 typedef struct VFmt VFmt;
 struct VFmt {
 	const char *fmt;
