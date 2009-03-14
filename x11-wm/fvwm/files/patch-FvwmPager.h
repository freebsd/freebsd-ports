--- ./modules/FvwmPager/FvwmPager.h.orig	1994-10-07 12:49:27.000000000 +0000
+++ ./modules/FvwmPager/FvwmPager.h	2009-03-11 09:42:48.000000000 +0000
@@ -1,3 +1,5 @@
+#include "../../libs/fvwmlib.h"
+
 typedef struct ScreenInfo
 {
   unsigned long screen;
@@ -83,7 +85,6 @@
  *************************************************************************/
 void Loop(int *fd);
 void SendInfo(int *fd,char *message,unsigned long window);
-char *safemalloc(int length);
 void DeadPipe(int nonsense);
 void process_message(unsigned long type,unsigned long *body);
 void ParseOptions(char *filename);
