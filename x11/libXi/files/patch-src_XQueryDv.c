From 5398ac0797f7516f2c9b8f2869a6c6d071437352 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sat, 27 Apr 2013 05:48:36 +0000
Subject: unvalidated lengths in XQueryDeviceState() [CVE-2013-1998 3/3]

If the lengths given for each class state in the reply add up to more
than the rep.length, we could read past the end of the buffer allocated
to hold the data read from the server.

Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
diff --git a/src/XQueryDv.c b/src/XQueryDv.c
index 69c285b..3836777 100644
--- src/XQueryDv.c
+++ src/XQueryDv.c
@@ -59,6 +59,7 @@ SOFTWARE.
 #include <X11/extensions/XInput.h>
 #include <X11/extensions/extutil.h>
 #include "XIint.h"
+#include <limits.h>
 
 XDeviceState *
 XQueryDeviceState(
@@ -66,8 +67,8 @@ XQueryDeviceState(
     XDevice		*dev)
 {
     int i, j;
-    int rlen;
-    int size = 0;
+    unsigned long rlen;
+    size_t size = 0;
     xQueryDeviceStateReq *req;
     xQueryDeviceStateReply rep;
     XDeviceState *state = NULL;
@@ -87,9 +88,11 @@ XQueryDeviceState(
     if (!_XReply(dpy, (xReply *) & rep, 0, xFalse))
         goto out;
 
-    rlen = rep.length << 2;
-    if (rlen > 0) {
-	data = Xmalloc(rlen);
+    if (rep.length > 0) {
+	if (rep.length < (INT_MAX >> 2)) {
+	    rlen = (unsigned long) rep.length << 2;
+	    data = Xmalloc(rlen);
+	}
 	if (!data) {
 	    _XEatDataWords(dpy, rep.length);
 	    goto out;
@@ -97,6 +100,10 @@ XQueryDeviceState(
 	_XRead(dpy, data, rlen);
 
 	for (i = 0, any = (XInputClass *) data; i < (int)rep.num_classes; i++) {
+	    if (any->length > rlen)
+		goto out;
+	    rlen -= any->length;
+
 	    switch (any->class) {
 	    case KeyClass:
 		size += sizeof(XKeyState);
--
cgit v0.9.0.2-2-gbebe
