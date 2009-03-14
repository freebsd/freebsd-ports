--- ./libs/hostname.c.orig	1994-09-22 12:37:18.000000000 +0000
+++ ./libs/hostname.c	2009-03-11 09:42:49.000000000 +0000
@@ -4,6 +4,7 @@
 /* define mygethostname() by using uname() */
 
 #include <sys/utsname.h>
+#include <string.h>
 
 int mygethostname(char *client, int length)
 {
