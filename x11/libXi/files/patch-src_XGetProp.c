From 6dd6dc51a2935c72774be81e5cc2ba2c30e9feff Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 06:55:23 +0000
Subject: integer overflow in XGetDeviceDontPropagateList() [CVE-2013-1984 3/8]

If the number of event classes reported by the server is large enough
that it overflows when multiplied by the size of the appropriate struct,
then memory corruption can occur when more bytes are copied from the
X server reply than the size of the buffer we allocated to hold them.

V2: EatData if count is 0 but length is > 0 to avoid XIOErrors

Reported-by: Ilja Van Sprundel <ivansprundel@ioactive.com>
Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
(limited to 'src/XGetProp.c')

--- src/XGetProp.c.orig	2011-12-20 00:28:44.000000000 +0000
+++ src/XGetProp.c	2013-05-29 16:49:01.000000000 +0000
@@ -60,6 +60,7 @@ SOFTWARE.
 #include <X11/extensions/XInput.h>
 #include <X11/extensions/extutil.h>
 #include "XIint.h"
+#include <limits.h>
 
 XEventClass *
 XGetDeviceDontPropagateList(
@@ -89,11 +90,11 @@ XGetDeviceDontPropagateList(
     }
     *count = rep.count;
 
-    if (*count) {
-	rlen = rep.length << 2;
-	list = (XEventClass *) Xmalloc(rep.length * sizeof(XEventClass));
+    if (rep.length != 0) {
+	if ((rep.count != 0) && (rep.length < (INT_MAX / sizeof(XEventClass))))
+	    list = Xmalloc(rep.length * sizeof(XEventClass));
 	if (list) {
-	    int i;
+	    unsigned int i;
 	    CARD32 ec;
 
 	    /* read and assign each XEventClass separately because
@@ -105,7 +106,7 @@ XGetDeviceDontPropagateList(
 		list[i] = (XEventClass) ec;
 	    }
 	} else
-	    _XEatData(dpy, (unsigned long)rlen);
+	    _XEatDataWords(dpy, rep.length);
     }
 
     UnlockDisplay(dpy);
