--- gnome-swallow.c.orig	Wed Apr 16 03:02:18 2003
+++ gnome-swallow.c	Wed Apr 16 03:05:58 2003
@@ -1,3 +1,5 @@
+#include <sys/types.h>
+#include <sys/time.h>
 #include <string.h>
 #include <stdio.h>
 
@@ -52,7 +54,7 @@
 
     XSync (display, FALSE);
 
-    gettimeofday(&tv);
+    gettimeofday(&tv, NULL);
     now = start = (double)tv.tv_sec + ((double)tv.tv_usec / 1000000.0);
 
     while (ready == FALSE && now < (start + 10.0))
@@ -128,7 +130,7 @@
         fprintf(stderr,"Loop");
         gtk_main_iteration_do(FALSE);
 
-        gettimeofday(&tv);
+        gettimeofday(&tv, NULL);
         now = (double)tv.tv_sec + ((double)tv.tv_usec / 1000000.0);
     }
 
