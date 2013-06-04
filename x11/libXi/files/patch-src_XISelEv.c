From 528419b9ef437e7eeafb41bf45e8ff7d818bd845 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 06:55:23 +0000
Subject: integer overflow in XIGetSelectedEvents() [CVE-2013-1984 6/8]

If the number of events or masks reported by the server is large enough
that it overflows when multiplied by the size of the appropriate struct,
or the sizes overflow as they are totaled up, then memory corruption can
occur when more bytes are copied from the X server reply than the size
of the buffer we allocated to hold them.

v2: check that reply size fits inside the data read from the server,
    so that we don't read out of bounds either

Reported-by: Ilja Van Sprundel <ivansprundel@ioactive.com>
Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
diff --git a/src/XISelEv.c b/src/XISelEv.c
index f871222..0471bef 100644
--- src/XISelEv.c
+++ src/XISelEv.c
@@ -42,6 +42,7 @@ in this Software without prior written authorization from the author.
 #include <X11/extensions/ge.h>
 #include <X11/extensions/geproto.h>
 #include "XIint.h"
+#include <limits.h>
 
 int
 XISelectEvents(Display* dpy, Window win, XIEventMask* masks, int num_masks)
@@ -101,13 +102,14 @@ out:
 XIEventMask*
 XIGetSelectedEvents(Display* dpy, Window win, int *num_masks_return)
 {
-    int i, len = 0;
+    unsigned int i, len = 0;
     unsigned char *mask;
     XIEventMask *mask_out = NULL;
     xXIEventMask *mask_in = NULL, *mi;
     xXIGetSelectedEventsReq *req;
     xXIGetSelectedEventsReply reply;
     XExtDisplayInfo *info = XInput_find_display(dpy);
+    size_t rbytes;
 
     *num_masks_return = -1;
     LockDisplay(dpy);
@@ -129,11 +131,16 @@ XIGetSelectedEvents(Display* dpy, Window win, int *num_masks_return)
         goto out;
     }
 
-    mask_in = Xmalloc(reply.length * 4);
-    if (!mask_in)
+    if (reply.length < (INT_MAX >> 2)) {
+        rbytes = (unsigned long) reply.length << 2;
+        mask_in = Xmalloc(rbytes);
+    }
+    if (!mask_in) {
+        _XEatDataWords(dpy, reply.length);
         goto out;
+    }
 
-    _XRead(dpy, (char*)mask_in, reply.length * 4);
+    _XRead(dpy, (char*)mask_in, rbytes);
 
     /*
      * This function takes interleaved xXIEventMask structs & masks off
@@ -148,8 +155,14 @@ XIGetSelectedEvents(Display* dpy, Window win, int *num_masks_return)
 
     for (i = 0, mi = mask_in; i < reply.num_masks; i++)
     {
-        len += mi->mask_len * 4;
-        mi = (xXIEventMask*)((char*)mi + mi->mask_len * 4);
+        unsigned int mask_bytes = mi->mask_len * 4;
+        len += mask_bytes;
+        if (len > INT_MAX)
+            goto out;
+        if ((sizeof(xXIEventMask) + mask_bytes) > rbytes)
+            goto out;
+        rbytes -= (sizeof(xXIEventMask) + mask_bytes);
+        mi = (xXIEventMask*)((char*)mi + mask_bytes);
         mi++;
     }
 
--
cgit v0.9.0.2-2-gbebe
