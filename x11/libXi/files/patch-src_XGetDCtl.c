From b0b13c12a8079a5a0e7f43b2b8983699057b2cec Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 06:55:23 +0000
Subject: integer overflow in XGetDeviceControl() [CVE-2013-1984 1/8]

If the number of valuators reported by the server is large enough that
it overflows when multiplied by the size of the appropriate struct, then
memory corruption can occur when more bytes are copied from the X server
reply than the size of the buffer we allocated to hold them.

v2: check that reply size fits inside the data read from the server, so
we don't read out of bounds either

Reported-by: Ilja Van Sprundel <ivansprundel@ioactive.com>
Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
diff --git a/src/XGetDCtl.c b/src/XGetDCtl.c
index f73a4e8..51ed0ae 100644
--- src/XGetDCtl.c
+++ src/XGetDCtl.c
@@ -61,6 +61,7 @@ SOFTWARE.
 #include <X11/extensions/XInput.h>
 #include <X11/extensions/extutil.h>
 #include "XIint.h"
+#include <limits.h>
 
 XDeviceControl *
 XGetDeviceControl(
@@ -68,8 +69,6 @@ XGetDeviceControl(
     XDevice		*dev,
     int			 control)
 {
-    int size = 0;
-    int nbytes, i;
     XDeviceControl *Device = NULL;
     XDeviceControl *Sav = NULL;
     xDeviceState *d = NULL;
@@ -92,8 +91,12 @@ XGetDeviceControl(
 	goto out;
 
     if (rep.length > 0) {
-	nbytes = (long)rep.length << 2;
-	d = (xDeviceState *) Xmalloc((unsigned)nbytes);
+	unsigned long nbytes;
+	size_t size = 0;
+	if (rep.length < (INT_MAX >> 2)) {
+	    nbytes = (unsigned long) rep.length << 2;
+	    d = Xmalloc(nbytes);
+	}
 	if (!d) {
 	    _XEatDataWords(dpy, rep.length);
 	    goto out;
@@ -111,33 +114,46 @@ XGetDeviceControl(
 	case DEVICE_RESOLUTION:
 	{
 	    xDeviceResolutionState *r;
+	    size_t val_size;
 
 	    r = (xDeviceResolutionState *) d;
-	    size += sizeof(XDeviceResolutionState) +
-		(3 * sizeof(int) * r->num_valuators);
+	    if (r->num_valuators >= (INT_MAX / (3 * sizeof(int))))
+		goto out;
+	    val_size = 3 * sizeof(int) * r->num_valuators;
+	    if ((sizeof(xDeviceResolutionState) + val_size) > nbytes)
+		goto out;
+	    size += sizeof(XDeviceResolutionState) + val_size;
 	    break;
 	}
         case DEVICE_ABS_CALIB:
         {
+            if (sizeof(xDeviceAbsCalibState) > nbytes)
+                goto out;
             size += sizeof(XDeviceAbsCalibState);
             break;
         }
         case DEVICE_ABS_AREA:
         {
+            if (sizeof(xDeviceAbsAreaState) > nbytes)
+                goto out;
             size += sizeof(XDeviceAbsAreaState);
             break;
         }
         case DEVICE_CORE:
         {
+            if (sizeof(xDeviceCoreState) > nbytes)
+                goto out;
             size += sizeof(XDeviceCoreState);
             break;
         }
 	default:
+	    if (d->length > nbytes)
+		goto out;
 	    size += d->length;
 	    break;
 	}
 
-	Device = (XDeviceControl *) Xmalloc((unsigned)size);
+	Device = Xmalloc(size);
 	if (!Device)
 	    goto out;
 
@@ -150,6 +166,7 @@ XGetDeviceControl(
 	    int *iptr, *iptr2;
 	    xDeviceResolutionState *r;
 	    XDeviceResolutionState *R;
+	    unsigned int i;
 
 	    r = (xDeviceResolutionState *) d;
 	    R = (XDeviceResolutionState *) Device;
--
cgit v0.9.0.2-2-gbebe
