--- src/XvMC.c.orig	2012-03-08 05:31:17.000000000 +0000
+++ src/XvMC.c	2013-06-03 19:17:33.000000000 +0000
@@ -16,6 +16,7 @@
 #include <sys/time.h>
 #include <X11/extensions/Xext.h>
 #include <X11/extensions/extutil.h>
+#include <limits.h>
 
 static XExtensionInfo _xvmc_info_data;
 static XExtensionInfo *xvmc_info = &_xvmc_info_data;
@@ -111,8 +112,8 @@ XvMCSurfaceInfo * XvMCListSurfaceTypes(D
     }
 
     if(rep.num > 0) {
-	surface_info =
-	    (XvMCSurfaceInfo*)Xmalloc(rep.num * sizeof(XvMCSurfaceInfo));
+        if (rep.num < (INT_MAX / sizeof(XvMCSurfaceInfo)))
+            surface_info = Xmalloc(rep.num * sizeof(XvMCSurfaceInfo));
 
         if(surface_info) {
 	    xvmcSurfaceInfo sinfo;
@@ -134,7 +135,7 @@ XvMCSurfaceInfo * XvMCListSurfaceTypes(D
 	       surface_info[i].flags = sinfo.flags;
 	    }
 	} else
-	   _XEatData(dpy, rep.length << 2);
+	   _XEatDataWords(dpy, rep.length);
     }
 
     UnlockDisplay (dpy);
@@ -172,8 +173,8 @@ XvImageFormatValues * XvMCListSubpicture
     }
 
     if(rep.num > 0) {
-        ret =
-	   (XvImageFormatValues*)Xmalloc(rep.num * sizeof(XvImageFormatValues));
+        if (rep.num < (INT_MAX / sizeof(XvImageFormatValues)))
+            ret = Xmalloc(rep.num * sizeof(XvImageFormatValues));
 
         if(ret) {
             xvImageFormatInfo Info;
@@ -207,7 +208,7 @@ XvImageFormatValues * XvMCListSubpicture
               ret[i].scanline_order = Info.scanline_order;
             }
         } else
-	   _XEatData(dpy, rep.length << 2);
+	   _XEatDataWords(dpy, rep.length);
     }
 
     UnlockDisplay (dpy);
@@ -273,12 +274,13 @@ Status _xvmc_create_context (
     context->flags = rep.flags_return;
 
     if(rep.length) {
-	*priv_data = Xmalloc(rep.length << 2);
+	if (rep.length < (INT_MAX >> 2))
+	    *priv_data = Xmalloc(rep.length << 2);
 	if(*priv_data) {
             _XRead(dpy, (char*)(*priv_data), rep.length << 2);
 	    *priv_count = rep.length;
 	} else
-	    _XEatData(dpy, rep.length << 2);
+	    _XEatDataWords(dpy, rep.length);
     }
 
     UnlockDisplay (dpy);
@@ -354,12 +356,13 @@ Status _xvmc_create_surface (
     }
 
     if(rep.length) {
-        *priv_data = Xmalloc(rep.length << 2);
+        if (rep.length < (INT_MAX >> 2))
+            *priv_data = Xmalloc(rep.length << 2);
         if(*priv_data) {
             _XRead(dpy, (char*)(*priv_data), rep.length << 2);
             *priv_count = rep.length;
         } else
-            _XEatData(dpy, rep.length << 2);
+            _XEatDataWords(dpy, rep.length);
     }
 
     UnlockDisplay (dpy);
@@ -444,12 +447,13 @@ Status _xvmc_create_subpicture (
     subpicture->component_order[3] = rep.component_order[3];
 
     if(rep.length) {
-        *priv_data = Xmalloc(rep.length << 2);
+        if (rep.length < (INT_MAX >> 2))
+            *priv_data = Xmalloc(rep.length << 2);
         if(*priv_data) {
             _XRead(dpy, (char*)(*priv_data), rep.length << 2);
             *priv_count = rep.length;
         } else
-            _XEatData(dpy, rep.length << 2);
+            _XEatDataWords(dpy, rep.length);
     }
 
     UnlockDisplay (dpy);
@@ -484,7 +488,6 @@ Status XvMCGetDRInfo(Display *dpy, XvPor
     XExtDisplayInfo *info = xvmc_find_display(dpy);
     xvmcGetDRInfoReply rep;
     xvmcGetDRInfoReq  *req;
-    char *tmpBuf = NULL;
     CARD32 magic;
 
 #ifdef HAVE_SHMAT
@@ -495,6 +498,9 @@ Status XvMCGetDRInfo(Display *dpy, XvPor
     here.tz_dsttime = 0;
 #endif
 
+    *name = NULL;
+    *busID = NULL;
+
     XvMCCheckExtension (dpy, info, BadImplementation);
 
     LockDisplay (dpy);
@@ -553,33 +559,33 @@ Status XvMCGetDRInfo(Display *dpy, XvPor
 #endif
 
     if (rep.length > 0) {
+	unsigned long realSize = 0;
+	char *tmpBuf = NULL;
 
-        int realSize = rep.length << 2;
-
-	tmpBuf = (char *) Xmalloc(realSize);
-	if (tmpBuf) {
-	    *name = (char *) Xmalloc(rep.nameLen);
-	    if (*name) {
-		*busID = (char *) Xmalloc(rep.busIDLen);
-		if (! *busID) {
-		    XFree(*name);
-		    XFree(tmpBuf);
-		}
-	    } else {
-		XFree(tmpBuf);
+	if (rep.length < (INT_MAX >> 2)) {
+	    realSize = rep.length << 2;
+	    if (realSize >= (rep.nameLen + rep.busIDLen)) {
+		tmpBuf = Xmalloc(realSize);
+		*name = Xmalloc(rep.nameLen);
+		*busID = Xmalloc(rep.busIDLen);
 	    }
 	}
 
 	if (*name && *busID && tmpBuf) {
-
 	    _XRead(dpy, tmpBuf, realSize);
 	    strncpy(*name,tmpBuf,rep.nameLen);
+	    (*name)[rep.nameLen - 1] = '\0';
 	    strncpy(*busID,tmpBuf+rep.nameLen,rep.busIDLen);
+	    (*busID)[rep.busIDLen - 1] = '\0';
 	    XFree(tmpBuf);
-
 	} else {
+	    XFree(*name);
+	    *name = NULL;
+	    XFree(*busID);
+	    *busID = NULL;
+	    XFree(tmpBuf);
 
-	    _XEatData(dpy, realSize);
+	    _XEatDataWords(dpy, rep.length);
 	    UnlockDisplay (dpy);
 	    SyncHandle ();
 	    return -1;
