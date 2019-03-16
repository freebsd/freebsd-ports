--- dmenu.c.orig	2019-02-28 14:52:56 UTC
+++ dmenu.c
@@ -665,7 +665,7 @@ setup(void)
 	                XNClientWindow, win, XNFocusWindow, win, NULL);
 
 	XMapRaised(dpy, win);
-	XSetInputFocus(dpy, win, RevertToParent, CurrentTime);
+	/* XSetInputFocus(dpy, win, RevertToParent, CurrentTime); */
 	if (embed) {
 		XSelectInput(dpy, parentwin, FocusChangeMask);
 		if (XQueryTree(dpy, parentwin, &dw, &w, &dws, &du) && dws) {
