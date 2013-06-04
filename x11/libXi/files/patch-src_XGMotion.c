From bb922ed4253b35590f0369f32a917ff89ade0830 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 06:55:23 +0000
Subject: integer overflow in XGetDeviceMotionEvents() [CVE-2013-1984 4/8]

If the number of events or axes reported by the server is large enough
that it overflows when multiplied by the size of the appropriate struct,
then memory corruption can occur when more bytes are copied from the
X server reply than the size of the buffer we allocated to hold them.

Reported-by: Ilja Van Sprundel <ivansprundel@ioactive.com>
Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
diff --git a/src/XGMotion.c b/src/XGMotion.c
index 5feac85..a4c75b6 100644
--- src/XGMotion.c
+++ src/XGMotion.c
@@ -59,6 +59,7 @@ SOFTWARE.
 #include <X11/extensions/XInput.h>
 #include <X11/extensions/extutil.h>
 #include "XIint.h"
+#include <limits.h>
 
 XDeviceTimeCoord *
 XGetDeviceMotionEvents(
@@ -74,7 +75,7 @@ XGetDeviceMotionEvents(
     xGetDeviceMotionEventsReply rep;
     XDeviceTimeCoord *tc;
     int *data, *bufp, *readp, *savp;
-    long size, size2;
+    unsigned long size;
     int i, j;
     XExtDisplayInfo *info = XInput_find_display(dpy);
 
@@ -104,10 +105,21 @@ XGetDeviceMotionEvents(
 	SyncHandle();
 	return (NULL);
     }
-    size = rep.length << 2;
-    size2 = rep.nEvents * (sizeof(XDeviceTimeCoord) + (rep.axes * sizeof(int)));
-    savp = readp = (int *)Xmalloc(size);
-    bufp = (int *)Xmalloc(size2);
+    if (rep.length < (INT_MAX >> 2)) {
+	size = rep.length << 2;
+	savp = readp = Xmalloc(size);
+    } else {
+	size = 0;
+	savp = readp = NULL;
+    }
+    /* rep.axes is a CARD8, so assume max number of axes for bounds check */
+    if (rep.nEvents <
+	(INT_MAX / (sizeof(XDeviceTimeCoord) + (UCHAR_MAX * sizeof(int))))) {
+	size_t bsize = rep.nEvents *
+	    (sizeof(XDeviceTimeCoord) + (rep.axes * sizeof(int)));
+	bufp = Xmalloc(bsize);
+    } else
+	bufp = NULL;
     if (!bufp || !savp) {
 	Xfree(bufp);
 	Xfree(savp);
--
cgit v0.9.0.2-2-gbebe
