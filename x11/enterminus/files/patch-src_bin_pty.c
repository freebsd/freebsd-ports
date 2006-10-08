--- src/bin/pty.c.orig	Mon Aug 14 18:25:18 2006
+++ src/bin/pty.c	Mon Aug 14 18:25:51 2006
@@ -19,7 +19,7 @@
    int fd;
    char *ptydev;
 
-   if((fd = getpt()) >= 0)
+   if((fd = posix_openpt(O_RDWR)) >= 0)
      {
 	if(grantpt(fd) == 0 && unlockpt(fd) == 0)
 	  {
