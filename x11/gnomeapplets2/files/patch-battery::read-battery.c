
$FreeBSD$

--- battery/read-battery.c	2002/01/14 14:23:46	1.1
+++ battery/read-battery.c	2002/01/14 14:25:45
@@ -170,7 +170,7 @@
   *hours_remaining = -1;
   *minutes_remaining = 1;
 
-  fd = open(APMDEV, O_RDWR);
+  fd = open(APMDEV, O_RDONLY);
   if (fd == -1)
     {
       g_error (_("Cannot open /dev/apm; can't get data."));
@@ -179,6 +179,7 @@
 
   if (ioctl(fd, APMIO_GETINFO, &aip) == -1) {
     g_error(_("ioctl failed on /dev/apm."));
+    close(fd);
     return FALSE;
   }
 
