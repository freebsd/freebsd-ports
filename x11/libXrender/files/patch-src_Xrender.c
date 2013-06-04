--- src/Xrender.c.orig	2013-06-03 19:11:25.000000000 +0000
+++ src/Xrender.c	2013-06-03 19:11:34.000000000 +0000
@@ -26,6 +26,7 @@
 #include <config.h>
 #endif
 #include "Xrenderint.h"
+#include <limits.h>
 
 XRenderExtInfo XRenderExtensionInfo;
 char XRenderExtensionName[] = RENDER_NAME;
@@ -411,8 +412,8 @@ XRenderQueryFormats (Display *dpy)
     CARD32			*xSubpixel;
     void			*xData;
     int				nf, ns, nd, nv;
-    int				rlength;
-    int				nbytes;
+    unsigned long		rlength;
+    unsigned long		nbytes;
 
     RenderCheckExtension (dpy, info, 0);
     LockDisplay (dpy);
@@ -458,24 +459,35 @@ XRenderQueryFormats (Display *dpy)
     if (async_state.major_version == 0 && async_state.minor_version < 6)
 	rep.numSubpixel = 0;
 
-    xri = (XRenderInfo *) Xmalloc (sizeof (XRenderInfo) +
-				   rep.numFormats * sizeof (XRenderPictFormat) +
-				   rep.numScreens * sizeof (XRenderScreen) +
-				   rep.numDepths * sizeof (XRenderDepth) +
-				   rep.numVisuals * sizeof (XRenderVisual));
-    rlength = (rep.numFormats * sizeof (xPictFormInfo) +
-	       rep.numScreens * sizeof (xPictScreen) +
-	       rep.numDepths * sizeof (xPictDepth) +
-	       rep.numVisuals * sizeof (xPictVisual) +
-	       rep.numSubpixel * 4);
-    xData = (void *) Xmalloc (rlength);
-    nbytes = (int) rep.length << 2;
+    if ((rep.numFormats < ((INT_MAX / 4) / sizeof (XRenderPictFormat))) &&
+	(rep.numScreens < ((INT_MAX / 4) / sizeof (XRenderScreen))) &&
+	(rep.numDepths  < ((INT_MAX / 4) / sizeof (XRenderDepth))) &&
+	(rep.numVisuals < ((INT_MAX / 4) / sizeof (XRenderVisual))) &&
+	(rep.numSubpixel < ((INT_MAX / 4) / 4)) &&
+	(rep.length < (INT_MAX >> 2)) ) {
+	xri = Xmalloc (sizeof (XRenderInfo) +
+		       (rep.numFormats * sizeof (XRenderPictFormat)) +
+		       (rep.numScreens * sizeof (XRenderScreen)) +
+		       (rep.numDepths * sizeof (XRenderDepth)) +
+		       (rep.numVisuals * sizeof (XRenderVisual)));
+	rlength = ((rep.numFormats * sizeof (xPictFormInfo)) +
+		   (rep.numScreens * sizeof (xPictScreen)) +
+		   (rep.numDepths * sizeof (xPictDepth)) +
+		   (rep.numVisuals * sizeof (xPictVisual)) +
+		   (rep.numSubpixel * 4));
+	xData = Xmalloc (rlength);
+	nbytes = (unsigned long) rep.length << 2;
+    } else {
+	xri = NULL;
+	xData = NULL;
+	rlength = nbytes = 0;
+    }
 
     if (!xri || !xData || nbytes < rlength)
     {
 	if (xri) Xfree (xri);
 	if (xData) Xfree (xData);
-	_XEatData (dpy, nbytes);
+	_XEatDataWords (dpy, rep.length);
 	UnlockDisplay (dpy);
 	SyncHandle ();
 	return 0;
@@ -832,7 +844,7 @@ XRenderQueryPictIndexValues(Display			*d
     xRenderQueryPictIndexValuesReq	*req;
     xRenderQueryPictIndexValuesReply	rep;
     XIndexValue				*values;
-    int					nbytes, nread, rlength, i;
+    unsigned int			nbytes, nread, rlength, i;
 
     RenderCheckExtension (dpy, info, NULL);
 
@@ -848,18 +860,25 @@ XRenderQueryPictIndexValues(Display			*d
 	return NULL;
     }
 
-    /* request data length */
-    nbytes = (long)rep.length << 2;
-    /* bytes of actual data in the request */
-    nread = rep.numIndexValues * SIZEOF (xIndexValue);
-    /* size of array returned to application */
-    rlength = rep.numIndexValues * sizeof (XIndexValue);
+    if ((rep.length < (INT_MAX >> 2)) &&
+	(rep.numIndexValues < (INT_MAX / sizeof (XIndexValue)))) {
+	/* request data length */
+	nbytes = rep.length << 2;
+	/* bytes of actual data in the request */
+	nread = rep.numIndexValues * SIZEOF (xIndexValue);
+	/* size of array returned to application */
+	rlength = rep.numIndexValues * sizeof (XIndexValue);
+
+	/* allocate returned data */
+	values = Xmalloc (rlength);
+    } else {
+	nbytes = nread = rlength = 0;
+	values = NULL;
+    }
 
-    /* allocate returned data */
-    values = (XIndexValue *)Xmalloc (rlength);
     if (!values)
     {
-	_XEatData (dpy, nbytes);
+	_XEatDataWords (dpy, rep.length);
 	UnlockDisplay (dpy);
 	SyncHandle ();
 	return NULL;
