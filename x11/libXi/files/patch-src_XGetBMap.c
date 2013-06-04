From f3e08e4fbe40016484ba795feecf1a742170ffc1 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 06:26:52 +0000
Subject: Stack buffer overflow in XGetDeviceButtonMapping() [CVE-2013-1998 1/3]

We copy the entire reply sent by the server into the fixed size
mapping[] array on the stack, even if the server says it's a larger
size than the mapping array can hold.  HULK SMASH STACK!

Reported-by: Ilja Van Sprundel <ivansprundel@ioactive.com>
Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
diff --git a/src/XGetBMap.c b/src/XGetBMap.c
index 211c9ca..002daba 100644
--- src/XGetBMap.c
+++ src/XGetBMap.c
@@ -60,6 +60,7 @@ SOFTWARE.
 #include <X11/extensions/XInput.h>
 #include <X11/extensions/extutil.h>
 #include "XIint.h"
+#include <limits.h>
 
 #ifdef MIN	/* some systems define this in <sys/param.h> */
 #undef MIN
@@ -75,7 +76,6 @@ XGetDeviceButtonMapping(
 {
     int status = 0;
     unsigned char mapping[256];	/* known fixed size */
-    long nbytes;
     XExtDisplayInfo *info = XInput_find_display(dpy);
 
     register xGetDeviceButtonMappingReq *req;
@@ -92,13 +92,18 @@ XGetDeviceButtonMapping(
 
     status = _XReply(dpy, (xReply *) & rep, 0, xFalse);
     if (status == 1) {
-	nbytes = (long)rep.length << 2;
-	_XRead(dpy, (char *)mapping, nbytes);
-
-	/* don't return more data than the user asked for. */
-	if (rep.nElts)
-	    memcpy((char *)map, (char *)mapping, MIN((int)rep.nElts, nmap));
-	status = rep.nElts;
+	if (rep.length <= (sizeof(mapping) >> 2)) {
+	    unsigned long nbytes = rep.length << 2;
+	    _XRead(dpy, (char *)mapping, nbytes);
+
+	    /* don't return more data than the user asked for. */
+	    if (rep.nElts)
+		memcpy(map, mapping, MIN((int)rep.nElts, nmap));
+	    status = rep.nElts;
+	} else {
+	    _XEatDataWords(dpy, rep.length);
+	    status = 0;
+	}
     } else
 	status = 0;
     UnlockDisplay(dpy);
--
cgit v0.9.0.2-2-gbebe
