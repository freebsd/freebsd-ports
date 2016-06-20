--- util.c.orig	2004-08-29 10:21:46 UTC
+++ util.c
@@ -735,7 +735,7 @@ int file_allowed(char *fname)
 
 struct WinAction *getRC()
 {
-	char fname[2][1024]={"","/etc/X11/imwheel/imwheelrc"}, line[1024], *p, *q, winid[1024];
+	char fname[2][1024]={"","/usr/X11R6/etc/imwheelrc"}, line[1024], *p, *q, winid[1024];
 	int fi,i;
 	struct WinAction *newwa=NULL;
 	FILE *f=NULL;
