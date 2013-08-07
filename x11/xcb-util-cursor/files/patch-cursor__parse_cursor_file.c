--- cursor/parse_cursor_file.c.orig	2013-08-07 21:57:33.658269610 +0200
+++ cursor/parse_cursor_file.c	2013-08-07 22:00:01.294253704 +0200
@@ -33,6 +33,7 @@
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/endian.h>
 #include <fcntl.h>
 #include <unistd.h>
 
