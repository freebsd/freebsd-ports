--- Services/User/Terminal/Headers/iTerm/PTYSession.h.orig	Sun Sep 17 21:03:24 2006
+++ Services/User/Terminal/Headers/iTerm/PTYSession.h	Tue Dec 19 07:29:49 2006
@@ -28,6 +28,7 @@
 #import <AppKit/AppKit.h>
 
 #include <sys/time.h>
+#include <pthread.h>
 
 @class PTYTask;
 @class PTYTextView;
