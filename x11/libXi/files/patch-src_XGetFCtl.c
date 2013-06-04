From 322ee3576789380222d4403366e4fd12fb24cb6a Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 06:55:23 +0000
Subject: integer overflow in XGetFeedbackControl() [CVE-2013-1984 2/8]

If the number of feedbacks reported by the server is large enough that
it overflows when multiplied by the size of the appropriate struct, or
if the total size of all the feedback structures overflows when added
together, then memory corruption can occur when more bytes are copied from
the X server reply than the size of the buffer we allocated to hold them.

v2: check that reply size fits inside the data read from the server, so
    we don't read out of bounds either

Reported-by: Ilja Van Sprundel <ivansprundel@ioactive.com>
Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
diff --git a/src/XGetFCtl.c b/src/XGetFCtl.c
index 28fab4d..bb50bf3 100644
--- src/XGetFCtl.c
+++ src/XGetFCtl.c
@@ -61,6 +61,7 @@ SOFTWARE.
 #include <X11/extensions/XInput.h>
 #include <X11/extensions/extutil.h>
 #include "XIint.h"
+#include <limits.h>
 
 XFeedbackState *
 XGetFeedbackControl(
@@ -68,8 +69,6 @@ XGetFeedbackControl(
     XDevice		*dev,
     int			*num_feedbacks)
 {
-    int size = 0;
-    int nbytes, i;
     XFeedbackState *Feedback = NULL;
     XFeedbackState *Sav = NULL;
     xFeedbackState *f = NULL;
@@ -91,9 +90,16 @@ XGetFeedbackControl(
 	goto out;
 
     if (rep.length > 0) {
+	unsigned long nbytes;
+	size_t size = 0;
+	int i;
+
 	*num_feedbacks = rep.num_feedbacks;
-	nbytes = (long)rep.length << 2;
-	f = (xFeedbackState *) Xmalloc((unsigned)nbytes);
+
+	if (rep.length < (INT_MAX >> 2)) {
+	    nbytes = rep.length << 2;
+	    f = Xmalloc(nbytes);
+	}
 	if (!f) {
 	    _XEatDataWords(dpy, rep.length);
 	    goto out;
@@ -102,6 +108,10 @@ XGetFeedbackControl(
 	_XRead(dpy, (char *)f, nbytes);
 
 	for (i = 0; i < *num_feedbacks; i++) {
+	    if (f->length > nbytes)
+		goto out;
+	    nbytes -= f->length;
+
 	    switch (f->class) {
 	    case KbdFeedbackClass:
 		size += sizeof(XKbdFeedbackState);
@@ -116,6 +126,8 @@ XGetFeedbackControl(
 	    {
 		xStringFeedbackState *strf = (xStringFeedbackState *) f;
 
+		if (strf->num_syms_supported >= (INT_MAX / sizeof(KeySym)))
+		    goto out;
 		size += sizeof(XStringFeedbackState) +
 		    (strf->num_syms_supported * sizeof(KeySym));
 	    }
@@ -130,10 +142,12 @@ XGetFeedbackControl(
 		size += f->length;
 		break;
 	    }
+	    if (size > INT_MAX)
+		goto out;
 	    f = (xFeedbackState *) ((char *)f + f->length);
 	}
 
-	Feedback = (XFeedbackState *) Xmalloc((unsigned)size);
+	Feedback = Xmalloc(size);
 	if (!Feedback)
 	    goto out;
 
--
cgit v0.9.0.2-2-gbebe
