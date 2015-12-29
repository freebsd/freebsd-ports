--- menus.c.orig	1995-02-09 20:09:18 UTC
+++ menus.c
@@ -2674,14 +2674,20 @@ ExecuteFunction(func, action, sub, w, tm
 	if (DeferExecution(context, func, action, Scr->SelectCursor))
 	    return TRUE;
 
-	if (tmp_win->isicon || !tmp_win->mapped )
-	{
+	if (tmp_win->isicon || !tmp_win->mapped ) {
 	    DeIconify(tmp_win);
 	}
-        else if (func == F_ICONIFY)
-	{
-	    Iconify (tmp_win, eventp->xbutton.x_root - 5,
-		     eventp->xbutton.y_root - 5);
+        else if (func == F_ICONIFY) {
+	    if ( tmp_win->root == Scr->VirtualDesktop ) {
+		Iconify (tmp_win,
+		    eventp->xbutton.x_root - 5 + Scr->vdtPositionX,
+		    eventp->xbutton.y_root - 5 + Scr->vdtPositionY
+		);
+	    }
+	    else {
+		Iconify (tmp_win, eventp->xbutton.x_root - 5,
+		    eventp->xbutton.y_root - 5);
+	    }
 	}
 	break;
 
@@ -3091,6 +3097,50 @@ ExecuteFunction(func, action, sub, w, tm
 	    RelativeMove(tmp_win, action);
 	break;
 
+    case F_DUMPSTATE:
+	printf("doing dumpstate\n");
+	{
+	    Window RootW;
+	    Window root, parent, *children;
+	    unsigned int nchildren;
+	    unsigned int numscr;
+	    unsigned int i;
+	    unsigned int scr;
+
+	    numscr = ScreenCount(dpy);
+	    printf("# of screens: %d\n",numscr);
+	    for(scr = 0; scr <= (numscr-1); scr++) {
+		RootW = RootWindow(dpy, scr);
+		printf("rootw: 0x%x\n",RootW);
+		XGrabServer(dpy);
+		XSync(dpy, 0);
+		XQueryTree(dpy, RootW, &root, &parent, &children, &nchildren);
+		for (i = 0; i < nchildren; i++) {
+		    if (children[i]) {
+			XWMHints *wmhintsp = XGetWMHints (dpy, children[i]);
+			if (wmhintsp) {
+			    if (wmhintsp->flags) {
+				printf("i: %d wmhints w: 0x%x flags: %d ",
+				    i,children[i], wmhintsp->flags
+				);
+			        if ( wmhintsp->flags & StateHint ) {
+				    printf("state: %d ",
+					wmhintsp->initial_state);
+				}
+				printf("\n");
+			    }
+			}
+		    }
+		    else {
+			printf(" NOT DEFINED\n");
+		    }
+		}
+	    }
+	    XUngrabServer(dpy);
+	    XFree(children);
+	}
+	break;
+
     case F_QUIT:
 	Done();
 	break;
@@ -3188,6 +3238,7 @@ int func;
 	case F_DESTROY:
 	case F_DELETE:
 	case F_DELETEORDESTROY:
+	case F_DUMPSTATE:
 	case F_WINREFRESH:
 	case F_ZOOM:
 	case F_FULLZOOM:
