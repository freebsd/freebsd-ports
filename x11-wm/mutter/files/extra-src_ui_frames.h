$OpenBSD: patch-src_ui_frames_h,v 1.1 2015/04/13 08:14:07 jasper Exp $
--- src/ui/frames.h.orig	Mon Apr 13 09:51:38 2015
+++ src/ui/frames.h	Mon Apr 13 09:55:33 2015
@@ -27,6 +27,7 @@
 #include <meta/common.h>
 #include <meta/types.h>
 #include "theme-private.h"
+#include "ui.h"
 
 typedef enum
 {
@@ -68,8 +69,6 @@ typedef enum
 
 typedef struct _MetaFrames        MetaFrames;
 typedef struct _MetaFramesClass   MetaFramesClass;
-
-typedef struct _MetaUIFrame         MetaUIFrame;
 
 struct _MetaUIFrame
 {
