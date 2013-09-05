--- gnome-swallow.c.orig	2003-09-12 00:21:55.000000000 -0400
+++ gnome-swallow.c	2013-09-05 17:51:55.000000000 -0400
@@ -1,5 +1,8 @@
+#include <sys/types.h>
+#include <sys/time.h>
 #include <string.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <signal.h>
 #include <sys/wait.h>
 
@@ -51,11 +54,11 @@ gboolean swallow(char* wantedWindow, Dis
     struct timeval tv;
     char ret;
 
-    if(! display) return; /* WTF? */
+    if(! display) return FALSE; /* WTF? */
 
     XSync (display, FALSE);
 
-    gettimeofday(&tv);
+    gettimeofday(&tv, NULL);
     now = start = (double)tv.tv_sec + ((double)tv.tv_usec / 1000000.0);
 
     while (ready == FALSE && now < (start + 10.0))
@@ -131,7 +134,7 @@ gboolean swallow(char* wantedWindow, Dis
         fprintf(stderr,"Loop");
         gtk_main_iteration_do(FALSE);
 
-        gettimeofday(&tv);
+        gettimeofday(&tv, NULL);
         now = (double)tv.tv_sec + ((double)tv.tv_usec / 1000000.0);
     }
 
@@ -249,13 +252,13 @@ void exitProgram(GtkWidget* w, gpointer 
 void forkApplet(struct AppletConfigure* ap)
 {
     if(ap->pid > -1) {
+        int s;
         /* Kill the old process and wait for it to die (if the process
            is already dead then it will be a zombie anyway).
          */
         kill(ap->pid, SIGTERM);
         sleep(1);
         kill(ap->pid, SIGKILL);
-        int s;
         waitpid(ap->pid, &s, WNOHANG);
     }
 
