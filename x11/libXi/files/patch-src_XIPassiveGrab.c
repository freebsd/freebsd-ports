From 91434737f592e8f5cc1762383882a582b55fc03a Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sun, 10 Mar 2013 07:37:23 +0000
Subject: memory corruption in _XIPassiveGrabDevice() [CVE-2013-1998 2/3]

If the server returned more modifiers than the caller asked for,
we'd just keep copying past the end of the array provided by the
caller, writing over who-knows-what happened to be there.

Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
---
diff --git a/src/XIPassiveGrab.c b/src/XIPassiveGrab.c
index ac17c01..53b4084 100644
--- src/XIPassiveGrab.c
+++ src/XIPassiveGrab.c
@@ -88,7 +88,7 @@ _XIPassiveGrabDevice(Display* dpy, int deviceid, int grabtype, int detail,
         return -1;
     _XRead(dpy, (char*)failed_mods, reply.num_modifiers * sizeof(xXIGrabModifierInfo));
 
-    for (i = 0; i < reply.num_modifiers; i++)
+    for (i = 0; i < reply.num_modifiers && i < num_modifiers; i++)
     {
         modifiers_inout[i].status = failed_mods[i].status;
         modifiers_inout[i].modifiers = failed_mods[i].modifiers;
--
cgit v0.9.0.2-2-gbebe
