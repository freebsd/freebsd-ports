--- util.c.orig	Tue Oct 31 13:06:05 2000
+++ util.c	Sat Jul 19 05:45:59 2003
@@ -330,11 +330,11 @@
 		fclose(f);
 		if(pid>0 && useFifo)
 		{
-			fprintf(stderr,"\
-ERROR: imwheel is already running or there is a stale pid file
-  check on processes listed below.
-  run with -k to kill running imwheels.
-  remove pid file %s.
+			fprintf(stderr,"\n\
+ERROR: imwheel is already running or there is a stale pid file\n\
+  check on processes listed below.\n\
+  run with -k to kill running imwheels.\n\
+  remove pid file %s.\n\
   or run with -p to avoid the pid file altogether.\n",PIDFILE);
 			if((f=fopen(PIDFILE,"r")))
 			{
@@ -710,7 +710,7 @@
 
 struct WinAction *getRC()
 {
-	char fname[2][1024]={"","/etc/imwheelrc"}, line[1024], *p, *q, winid[1024];
+	char fname[2][1024]={"","/usr/X11R6/etc/imwheelrc"}, line[1024], *p, *q, winid[1024];
 	int fi,i;
 	struct WinAction *newwa=NULL;
 	FILE *f=NULL;
