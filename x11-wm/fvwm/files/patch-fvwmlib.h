--- ./libs/fvwmlib.h.orig	1994-09-16 14:47:13.000000000 +0000
+++ ./libs/fvwmlib.h	2009-03-11 09:42:44.000000000 +0000
@@ -4,7 +4,7 @@
 int mygethostname(char *client, int namelen);
 void SendText(int *fd,char *message,unsigned long window);
 void SendInfo(int *fd,char *message,unsigned long window);
-char *safemalloc(int);
+void *safemalloc(unsigned int);
 char *findIconFile(char *icon, char *pathlist, int type);
 int ReadFvwmPacket(int fd, unsigned long *header, unsigned long **body);
 void CopyString(char **dest, char *source);
