--- ./modules/FvwmScroll/FvwmScroll.h.orig	1994-09-14 14:11:35.000000000 +0000
+++ ./modules/FvwmScroll/FvwmScroll.h	2009-03-11 09:42:48.000000000 +0000
@@ -1,5 +1,4 @@
 #include "../../libs/fvwmlib.h"       
-char *safemalloc(int length);
 void DeadPipe(int nonsense);
 void GetTargetWindow(Window *app_win);
 void sleep_a_little(int n);
