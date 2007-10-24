--- src/gdm-queue.c.orig	2007-04-09 12:01:03.000000000 -0400
+++ src/gdm-queue.c	2007-08-08 15:18:12.000000000 -0400
@@ -32,6 +32,7 @@
 #include <sys/stat.h>
 #include <sys/un.h>
 #include <errno.h>
+#include <signal.h>
 #include <stdio.h>
 
 #include "gdm-queue.h"
@@ -237,7 +238,7 @@ gboolean gdm_run_queue (void *dummy)
 
         if (stat (GDM_NEW_SOCKET_FILENAME, &file_stat) == 0)
           strcpy (addr.sun_path, GDM_NEW_SOCKET_FILENAME);
-        if (stat (GDM_OLD_SOCKET_FILENAME, &file_stat) == 0)
+	else if (stat (GDM_OLD_SOCKET_FILENAME, &file_stat) == 0)
           strcpy (addr.sun_path, GDM_OLD_SOCKET_FILENAME);
         else
           g_error ("Can't find gdm socket!");
