--- util.c.orig Sun Aug 29 06:21:46 2004
+++ util.c      Sun Nov  7 09:10:33 2004
@@ -735,7 +735,7 @@

 struct WinAction *getRC()
 {
-	char fname[2][1024]={"","/etc/X11/imwheel/imwheelrc"}, line[1024], *p, *q, winid[1024];
+	char fname[2][1024]={"","/usr/X11R6/etc/imwheelrc"}, line[1024], *p, *q, winid[1024];
	int fi,i;
	struct WinAction *newwa=NULL;
	FILE *f=NULL;

