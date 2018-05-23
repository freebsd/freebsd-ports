--- xcompmgr.c.orig	2015-04-17 05:56:17 UTC
+++ xcompmgr.c
@@ -1028,7 +1028,6 @@ paint_all (Display *dpy, XserverRegion region)
 	{
 	    w->borderClip = XFixesCreateRegion (dpy, NULL, 0);
 	    XFixesCopyRegion (dpy, w->borderClip, region);
-	    XFixesIntersectRegion(dpy, w->borderClip, w->borderClip, w->borderSize);
 	}
 	w->prev_trans = t;
 	t = w;
@@ -1080,6 +1079,8 @@ paint_all (Display *dpy, XserverRegion region)
 	if (w->mode == WINDOW_TRANS)
 	{
 	    int	x, y, wid, hei;
+	    XFixesIntersectRegion(dpy, w->borderClip, w->borderClip, w->borderSize);
+	    XFixesSetPictureClipRegion(dpy, rootBuffer, 0, 0, w->borderClip);
 #if HAS_NAME_WINDOW_PIXMAP
 	    x = w->a.x;
 	    y = w->a.y;
@@ -1099,6 +1100,8 @@ paint_all (Display *dpy, XserverRegion region)
 	else if (w->mode == WINDOW_ARGB)
 	{
 	    int	x, y, wid, hei;
+	    XFixesIntersectRegion(dpy, w->borderClip, w->borderClip, w->borderSize);
+	    XFixesSetPictureClipRegion(dpy, rootBuffer, 0, 0, w->borderClip);
 #if HAS_NAME_WINDOW_PIXMAP
 	    x = w->a.x;
 	    y = w->a.y;
