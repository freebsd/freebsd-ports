--- NickSpace.bproj/NickSpaceView.m.orig	2005-06-28 01:53:04.000000000 +0200
+++ NickSpace.bproj/NickSpaceView.m	2012-01-14 00:11:01.000000000 +0100
@@ -1,6 +1,8 @@
 #import "NickSpaceView.h"
 #import <AppKit/AppKit.h>
+#if !defined(__FreeBSD__)
 #import <values.h>
+#endif
 #import <time.h>
 #import <limits.h>
 
