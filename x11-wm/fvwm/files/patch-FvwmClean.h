--- ./modules/FvwmClean/FvwmClean.h.orig	1994-09-13 18:24:26.000000000 +0000
+++ ./modules/FvwmClean/FvwmClean.h	2009-03-11 09:42:48.000000000 +0000
@@ -18,7 +18,6 @@
  *************************************************************************/
 void Loop(int *fd);
 void SendInfo(int *fd,char *message,unsigned long window);
-char *safemalloc(int length);
 struct list *find_window(unsigned long id);
 void remove_window(unsigned long id);
 void add_window(unsigned long new_win);
