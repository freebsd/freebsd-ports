--- src/Filter.c.orig	2013-06-03 19:11:25.000000000 +0000
+++ src/Filter.c	2013-06-03 19:11:31.000000000 +0000
@@ -25,6 +25,7 @@
 #include <config.h>
 #endif
 #include "Xrenderint.h"
+#include <limits.h>
 
 XFilters *
 XRenderQueryFilters (Display *dpy, Drawable drawable)
@@ -37,7 +38,7 @@ XRenderQueryFilters (Display *dpy, Drawa
     char			*name;
     char			len;
     int				i;
-    long			nbytes, nbytesAlias, nbytesName;
+    unsigned long		nbytes, nbytesAlias, nbytesName;
 
     if (!RenderHasExtension (info))
 	return NULL;
@@ -60,26 +61,36 @@ XRenderQueryFilters (Display *dpy, Drawa
 	SyncHandle ();
 	return NULL;
     }
-    /*
-     * Compute total number of bytes for filter names
-     */
-    nbytes = (long)rep.length << 2;
-    nbytesAlias = rep.numAliases * 2;
-    if (rep.numAliases & 1)
-	nbytesAlias += 2;
-    nbytesName = nbytes - nbytesAlias;
 
     /*
-     * Allocate one giant block for the whole data structure
+     * Limit each component of combined size to 1/4 the max, which is far
+     * more than they should ever possibly need.
      */
-    filters = Xmalloc (sizeof (XFilters) +
-		       rep.numFilters * sizeof (char *) +
-		       rep.numAliases * sizeof (short) +
-		       nbytesName);
+    if ((rep.length < (INT_MAX >> 2)) &&
+	(rep.numFilters < ((INT_MAX / 4) / sizeof (char *))) &&
+	(rep.numAliases < ((INT_MAX / 4) / sizeof (short)))) {
+	/*
+	 * Compute total number of bytes for filter names
+	 */
+	nbytes = (unsigned long)rep.length << 2;
+	nbytesAlias = rep.numAliases * 2;
+	if (rep.numAliases & 1)
+	    nbytesAlias += 2;
+	nbytesName = nbytes - nbytesAlias;
+
+	/*
+	 * Allocate one giant block for the whole data structure
+	 */
+	filters = Xmalloc (sizeof (XFilters) +
+			   (rep.numFilters * sizeof (char *)) +
+			   (rep.numAliases * sizeof (short)) +
+			   nbytesName);
+    } else
+	filters = NULL;
 
     if (!filters)
     {
-	_XEatData (dpy, (unsigned long) rep.length << 2);
+	_XEatDataWords(dpy, rep.length);
 	UnlockDisplay (dpy);
 	SyncHandle ();
 	return NULL;
