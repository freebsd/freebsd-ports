--- ./modules/FvwmSave/FvwmSave.h.orig	1994-09-13 18:25:36.000000000 +0000
+++ ./modules/FvwmSave/FvwmSave.h	2009-03-11 09:42:48.000000000 +0000
@@ -26,7 +26,6 @@
  *************************************************************************/
 void Loop(int *fd);
 void SendInfo(int *fd,char *message,unsigned long window);
-char *safemalloc(int length);
 struct list *find_window(unsigned long id);
 void add_window(unsigned long new_win, unsigned long *body);
 void DeadPipe(int nonsense);
