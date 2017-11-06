--- NickSpace.bproj/NickSpaceView.m.orig	2005-06-27 23:53:04 UTC
+++ NickSpace.bproj/NickSpaceView.m
@@ -1,6 +1,8 @@
 #import "NickSpaceView.h"
 #import <AppKit/AppKit.h>
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 #import <values.h>
+#endif
 #import <time.h>
 #import <limits.h>
 
