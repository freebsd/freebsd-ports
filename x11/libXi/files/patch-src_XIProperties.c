From 242f92b490a695fbab244af5bad11b71f897c732 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 06:55:23 +0000
Subject: integer overflow in XIGetProperty() [CVE-2013-1984 5/8]

If the number of items reported by the server is large enough that
it overflows when multiplied by the size of the appropriate item type,
then memory corruption can occur when more bytes are copied from the
X server reply than the size of the buffer we allocated to hold them.

Reported-by: Ilja Van Sprundel <ivansprundel@ioactive.com>
Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
diff --git a/src/XIProperties.c b/src/XIProperties.c
index 5e58fb6..32436d1 100644
--- src/XIProperties.c
+++ src/XIProperties.c
@@ -38,6 +38,7 @@
 #include <X11/extensions/XInput2.h>
 #include <X11/extensions/extutil.h>
 #include "XIint.h"
+#include <limits.h>
 
 Atom*
 XIListProperties(Display* dpy, int deviceid, int *num_props_return)
@@ -170,7 +171,7 @@ XIGetProperty(Display* dpy, int deviceid, Atom property, long offset,
 {
     xXIGetPropertyReq   *req;
     xXIGetPropertyReply rep;
-    long                    nbytes, rbytes;
+    unsigned long       nbytes, rbytes;
 
     XExtDisplayInfo *info = XInput_find_display(dpy);
 
@@ -216,9 +217,11 @@ XIGetProperty(Display* dpy, int deviceid, Atom property, long offset,
 	 * recopy the string to make it null terminated.
 	 */
 
-        nbytes = rep.num_items * rep.format/8;
-        rbytes = nbytes + 1;
-        *data = Xmalloc(rbytes);
+	if (rep.num_items < (INT_MAX / (rep.format/8))) {
+	    nbytes = rep.num_items * rep.format/8;
+	    rbytes = nbytes + 1;
+	    *data = Xmalloc(rbytes);
+	}
 
 	if (!(*data)) {
 	    _XEatDataWords(dpy, rep.length);
--
cgit v0.9.0.2-2-gbebe
