--- lib/libolgx/ol_init.c.orig	Mon Sep 29 00:02:39 2003
+++ lib/libolgx/ol_init.c	Mon Sep 29 00:02:39 2003
@@ -9,7 +9,10 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/param.h>
+#ifndef __STDC__
 #include <malloc.h>
+#endif
 #include <X11/Xlib.h>
 #include "olgx_impl.h"
 #include "busy.h"
@@ -699,7 +702,17 @@
 	    XSetFont(info->dpy, info->gc_rec[OLGX_TEXTGC]->gc,
 		     info->textfont->fid);
 
+ 	    /* Even if !three_d, OLGX_TEXTGC_REV doesn't necessarily exist,
+	     * so we only set the font, if it does. I don't know if this is
+	     * the right place to change it, but this fixes a bug reported
+	     * on alt.toolkits.xview.
+	     * martin-2.buck@student.uni-ulm.de
+	     */
+#if 1
+	    if (!info->three_d && info->gc_rec[OLGX_TEXTGC_REV])
+#else
 	    if (!info->three_d)
+#endif
 		/* Only 2d has TEXTGC_REV */
 		XSetFont(info->dpy, info->gc_rec[OLGX_TEXTGC_REV]->gc,
 			 info->textfont->fid);
@@ -711,8 +724,15 @@
 	 */
 
 	XSetFont(info->dpy, info->gc_rec[OLGX_TEXTGC]->gc, font_info->fid);
+	/* See comment above.
+	 * martin-2.buck@student.uni-ulm.de
+	 */
+#if 1
+	if (!info->three_d && info->gc_rec[OLGX_TEXTGC_REV])
+#else
 
 	if (!info->three_d)
+#endif
 	    /* Only 2d has TEXTGC_REV */
           XSetFont(info->dpy, info->gc_rec[OLGX_TEXTGC_REV]->gc, font_info->fid);
 #endif
@@ -925,7 +945,14 @@
     if (! (Olgx_Flags(info) & OLGX_FONTSET)) {
 #endif
     info->gc_rec[OLGX_TEXTGC]->values.font = info->textfont->fid;
+    /* See comment above.
+     * martin-2.buck@student.uni-ulm.de
+     */
+#if 1
+    if (!info->three_d && info->gc_rec[OLGX_TEXTGC_REV])
+#else
     if (!info->three_d)
+#endif
 	info->gc_rec[OLGX_TEXTGC_REV]->values.font = info->textfont->fid;
 #ifdef OW_I18N
     }
