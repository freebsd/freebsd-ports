--- gnome-swallow.c.orig	Fri Sep 12 00:21:55 2003
+++ gnome-swallow.c	Sun Apr 24 00:28:34 2005
@@ -1,3 +1,5 @@
+#include <sys/types.h>
+#include <sys/time.h>
 #include <string.h>
 #include <stdio.h>
 #include <signal.h>
@@ -55,7 +57,7 @@ gboolean swallow(char* wantedWindow, Dis
 
     XSync (display, FALSE);
 
-    gettimeofday(&tv);
+    gettimeofday(&tv, NULL);
     now = start = (double)tv.tv_sec + ((double)tv.tv_usec / 1000000.0);
 
     while (ready == FALSE && now < (start + 10.0))
@@ -131,7 +133,7 @@ gboolean swallow(char* wantedWindow, Dis
         fprintf(stderr,"Loop");
         gtk_main_iteration_do(FALSE);
 
-        gettimeofday(&tv);
+        gettimeofday(&tv, NULL);
         now = (double)tv.tv_sec + ((double)tv.tv_usec / 1000000.0);
     }
 
@@ -249,13 +251,13 @@ void exitProgram(GtkWidget* w, gpointer 
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
 
