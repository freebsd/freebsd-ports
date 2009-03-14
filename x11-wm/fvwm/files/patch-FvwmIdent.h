--- ./modules/FvwmIdent/FvwmIdent.h.orig	1994-09-13 18:25:16.000000000 +0000
+++ ./modules/FvwmIdent/FvwmIdent.h	2009-03-11 09:42:48.000000000 +0000
@@ -42,7 +42,6 @@
  *************************************************************************/
 void Loop(int *fd);
 void SendInfo(int *fd,char *message,unsigned long window);
-char *safemalloc(int length);
 void DeadPipe(int nonsense);
 void process_message(unsigned long type,unsigned long *body);
 void GetTargetWindow(Window *app_win);
