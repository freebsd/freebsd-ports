--- afterstep/functions.c.orig	1997-04-26 12:50:08 UTC
+++ afterstep/functions.c
@@ -1257,7 +1257,7 @@ void Shade(ASWindow *tmp_win)
       tmp_win->flags |= SHADED;
 	
 	/* can't shade a window with no titlebar */
-	if (!tmp_win->flags & TITLE) return;
+	if ((!tmp_win->flags) & TITLE) return;
 
 #ifdef SHADE_ANIMATION
 	XLowerWindow(dpy, tmp_win->w);
