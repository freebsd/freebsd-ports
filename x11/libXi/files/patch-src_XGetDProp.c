From 17071c1c608247800b2ca03a35b1fcc9c4cabe6c Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 20:30:55 +0000
Subject: Avoid integer overflow in XGetDeviceProperties() [CVE-2013-1984 7/8]

If the number of items as reported by the Xserver is too large, it
could overflow the calculation for the size of the buffer to copy the
reply into, causing memory corruption.

Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
--- src/XGetDProp.c.orig	2010-09-07 05:21:05.000000000 +0000
+++ src/XGetDProp.c	2013-05-29 16:46:04.000000000 +0000
@@ -38,6 +38,7 @@ in this Software without prior written a
 #include <X11/extensions/XInput.h>
 #include <X11/extensions/extutil.h>
 #include "XIint.h"
+#include <limits.h>
 
 int
 XGetDeviceProperty(Display* dpy, XDevice* dev,
@@ -48,7 +49,8 @@ XGetDeviceProperty(Display* dpy, XDevice
 {
     xGetDevicePropertyReq   *req;
     xGetDevicePropertyReply rep;
-    long                    nbytes, rbytes;
+    unsigned long           nbytes, rbytes;
+    int                     ret = Success;
 
     XExtDisplayInfo *info = XInput_find_display(dpy);
 
@@ -81,30 +83,43 @@ XGetDeviceProperty(Display* dpy, XDevice
 	 * data, but this last byte is null terminated and convenient for
 	 * returning string properties, so the client doesn't then have to
 	 * recopy the string to make it null terminated.
+	 *
+	 * Maximum item limits are set to both prevent integer overflow when
+	 * calculating the amount of memory to malloc, and to limit how much
+	 * memory will be used if a server provides an insanely high count.
 	 */
 	switch (rep.format) {
 	case 8:
-	    nbytes = rep.nItems;
-	    rbytes = rep.nItems + 1;
-	    if (rbytes > 0 &&
-		(*prop = (unsigned char *) Xmalloc ((unsigned)rbytes)))
-		_XReadPad (dpy, (char *) *prop, nbytes);
+	    if (rep.nItems < INT_MAX) {
+		nbytes = rep.nItems;
+		rbytes = rep.nItems + 1;
+		if ((*prop = Xmalloc (rbytes)))
+		    _XReadPad (dpy, (char *) *prop, nbytes);
+		else
+		    ret = BadAlloc;
+	    }
 	    break;
 
 	case 16:
-	    nbytes = rep.nItems << 1;
-	    rbytes = rep.nItems * sizeof (short) + 1;
-	    if (rbytes > 0 &&
-		(*prop = (unsigned char *) Xmalloc ((unsigned)rbytes)))
-		_XRead16Pad (dpy, (short *) *prop, nbytes);
+	    if (rep.nItems < (INT_MAX / sizeof (short))) {
+		nbytes = rep.nItems << 1;
+		rbytes = rep.nItems * sizeof (short) + 1;
+		if ((*prop = Xmalloc (rbytes)))
+		    _XRead16Pad (dpy, (short *) *prop, nbytes);
+		else
+		    ret = BadAlloc;
+	    }
 	    break;
 
 	case 32:
-	    nbytes = rep.nItems << 2;
-	    rbytes = rep.nItems * sizeof (long) + 1;
-	    if (rbytes > 0 &&
-		(*prop = (unsigned char *) Xmalloc ((unsigned)rbytes)))
-		_XRead32 (dpy, (long *) *prop, nbytes);
+	    if (rep.nItems < (INT_MAX / sizeof (long))) {
+		nbytes = rep.nItems << 2;
+		rbytes = rep.nItems * sizeof (long) + 1;
+		if ((*prop = Xmalloc (rbytes)))
+		    _XRead32 (dpy, (long *) *prop, nbytes);
+		else
+		    ret = BadAlloc;
+	    }
 	    break;
 
 	default:
@@ -112,17 +127,13 @@ XGetDeviceProperty(Display* dpy, XDevice
 	     * This part of the code should never be reached.  If it is,
 	     * the server sent back a property with an invalid format.
 	     */
-	    nbytes = rep.length << 2;
-	    _XEatData(dpy, (unsigned long) nbytes);
-	    UnlockDisplay(dpy);
-	    SyncHandle();
-	    return(BadImplementation);
+	    ret = BadImplementation;
 	}
 	if (! *prop) {
-	    _XEatData(dpy, (unsigned long) nbytes);
-	    UnlockDisplay(dpy);
-	    SyncHandle();
-	    return(BadAlloc);
+	    _XEatDataWords(dpy, rep.length);
+	    if (ret == Success)
+		ret = BadAlloc;
+	    goto out;
 	}
 	(*prop)[rbytes - 1] = '\0';
     }
@@ -131,9 +142,10 @@ XGetDeviceProperty(Display* dpy, XDevice
     *actual_format = rep.format;
     *nitems = rep.nItems;
     *bytes_after = rep.bytesAfter;
+  out:
     UnlockDisplay (dpy);
     SyncHandle ();
 
-    return Success;
+    return ret;
 }
 
