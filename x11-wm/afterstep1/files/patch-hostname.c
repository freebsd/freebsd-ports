--- lib/hostname.c.orig	1996-08-21 14:23:34 UTC
+++ lib/hostname.c
@@ -3,6 +3,7 @@
 #if HAVE_UNAME
 /* define mygethostname() by using uname() */
 
+#include <string.h>
 #include <sys/utsname.h>
 
 int mygethostname(char *client, int length)
