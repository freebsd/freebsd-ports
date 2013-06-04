From 81b4df8ac6aa1520c41c3526961014a6f115cc46 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 08:16:22 +0000
Subject: sign extension issue in XListInputDevices() [CVE-2013-1995]

nptr is (signed) char, which can be negative, and will sign extend
when added to the int size, which means size can be subtracted from,
leading to allocating too small a buffer to hold the data being copied
from the X server's reply.

v2: check that string size fits inside the data read from the server,
    so that we don't read out of bounds either

Reported-by: Ilja Van Sprundel <ivansprundel@ioactive.com>
Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
diff --git a/src/XListDev.c b/src/XListDev.c
index 1c14b96..b85ff3c 100644
--- src/XListDev.c
+++ src/XListDev.c
@@ -73,7 +73,7 @@ static int pad_to_xid(int base_size)
     return ((base_size + padsize - 1)/padsize) * padsize;
 }
 
-static int
+static size_t
 SizeClassInfo(xAnyClassPtr *any, int num_classes)
 {
     int size = 0;
@@ -170,7 +170,7 @@ XListInputDevices(
     register Display	*dpy,
     int			*ndevices)
 {
-    int size;
+    size_t size;
     xListInputDevicesReq *req;
     xListInputDevicesReply rep;
     xDeviceInfo *list, *slist = NULL;
@@ -178,7 +178,7 @@ XListInputDevices(
     XDeviceInfo *clist = NULL;
     xAnyClassPtr any, sav_any;
     XAnyClassPtr Any;
-    char *nptr, *Nptr;
+    unsigned char *nptr, *Nptr;
     int i;
     unsigned long rlen;
     XExtDisplayInfo *info = XInput_find_display(dpy);
@@ -217,9 +217,12 @@ XListInputDevices(
             size += SizeClassInfo(&any, (int)list->num_classes);
 	}
 
-	for (i = 0, nptr = (char *)any; i < *ndevices; i++) {
+	Nptr = ((unsigned char *)list) + rlen + 1;
+	for (i = 0, nptr = (unsigned char *)any; i < *ndevices; i++) {
 	    size += *nptr + 1;
 	    nptr += (*nptr + 1);
+	    if (nptr > Nptr)
+		goto out;
 	}
 
 	clist = (XDeviceInfoPtr) Xmalloc(size);
@@ -245,8 +248,8 @@ XListInputDevices(
 	}
 
 	clist = sclist;
-	nptr = (char *)any;
-	Nptr = (char *)Any;
+	nptr = (unsigned char *)any;
+	Nptr = (unsigned char *)Any;
 	for (i = 0; i < *ndevices; i++, clist++) {
 	    clist->name = (char *)Nptr;
 	    memcpy(Nptr, nptr + 1, *nptr);
@@ -256,6 +259,7 @@ XListInputDevices(
 	}
     }
 
+  out:
     XFree((char *)slist);
     UnlockDisplay(dpy);
     SyncHandle();
--
cgit v0.9.0.2-2-gbebe
