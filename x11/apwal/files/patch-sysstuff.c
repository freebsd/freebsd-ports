--- sysstuff.c.orig	Wed Dec  3 09:58:17 2003
+++ sysstuff.c	Wed Dec  3 09:58:45 2003
@@ -370,7 +370,7 @@
   len = strlen(procfile);
   pid = getpid();
   sprintf(procfile + len, "%d", pid);
-  strcat(procfile, "/exe");
+  strcat(procfile, "/file");
 
   // read procfile to get the binary file of apwal
   cc = readlink(procfile, execfile, FILENAME_MAX);
