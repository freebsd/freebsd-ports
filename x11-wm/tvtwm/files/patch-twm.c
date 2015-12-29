--- twm.c.orig	1995-02-03 00:14:17 UTC
+++ twm.c
@@ -185,6 +185,9 @@ static int RedirectError;	/* TRUE ==> an
 static int CatchRedirectError();	/* for settting RedirectError */
 static int TwmErrorHandler();	/* for everything else */
 static void SetRootProperties();	/* leave note on root window */
+static void DisplayHints(XSizeHints *); /* PI-FIX */
+static void calcgeo(Display *, Drawable, int *, int *, int *, int *);	/* PI-FIX */
+
 char Info[INFO_LINES][INFO_SIZE];		/* info strings to print */
 int InfoLines;
 char *InitFile = NULL;
@@ -248,6 +251,14 @@ main(argc, argv, environ)
     int i, j, sync = FALSE;
     unsigned long valuemask;	/* mask for create windows */
     XSetWindowAttributes attributes;	/* attributes for create windows */
+/* PI-FIX */
+    XSizeHints mywmhints;
+    long mylong;
+    int res;
+    int minx = 0, miny = 0;
+    int *relx, *rely;
+    int rx, ry;
+/* PI-FIX */
     int numManaged, firstscrn, lastscrn, scrnum;
     extern ColormapWindow *CreateColormapWindow();
     SIGNAL_T QueueRestartTwm();
@@ -629,6 +640,67 @@ main(argc, argv, environ)
 	    Scr->iconmgr.twm_win->isicon = TRUE;
 
 	/*
+	 * allocate some space for relx, rely values
+	 */
+	relx = (int *) malloc(nchildren * sizeof(int));
+	rely = (int *) malloc(nchildren * sizeof(int));
+
+	/*
+	 * print a lot of information for each children
+	 */
+	for (i = 0; i < nchildren; i++) {
+	    if (children[i]) {
+		XWMHints *wmhintsp = XGetWMHints (dpy, children[i]);
+
+#ifdef DEBUG
+		if (wmhintsp) {
+		    if (wmhintsp->flags) {
+			printf("  wmhints i: %d w: 0x%x flags: %d ",
+			    i,children[i], wmhintsp->flags
+			);
+			if ( wmhintsp->flags & StateHint ) {
+			    printf("state: %d ",wmhintsp->initial_state);
+			}
+			printf("\n");
+		    }
+		}
+		res = XGetWMNormalHints(dpy, children[i], &mywmhints, &mylong);
+		if (res != 0) {
+		    DisplayHints(&mywmhints);
+		}
+		res = XGetWMSizeHints(dpy, children[i], &mywmhints, &mylong,
+		    XA_WM_ZOOM_HINTS);
+		if ( res != 0 ) {
+		    DisplayHints(&mywmhints);
+		}
+		else {
+		    printf("   no zoom hints\n");
+		}
+#endif
+		calcgeo(dpy, children[i], &minx, &miny, &rx, &ry);
+		relx[i] = rx;
+		rely[i] = ry;
+	    }
+	}
+
+#ifdef DEBUG
+	printf("minx: %d miny: %d\n", minx, miny);
+#endif
+
+	/*
+	 * move each children in the positive
+	 */
+	for (i = 0; i < nchildren; i++) {
+	    if (children[i]) {
+		if ( children[i] != Scr->Panner &&
+		     children[i] != Scr->VirtualDesktop) {
+		    /* HACK: only relx gets corrected */
+		    res = XMoveWindow(dpy, children[i], relx[i]-minx, rely[i]);
+		}
+	    }
+	}
+
+	/*
 	 * weed out icon windows
 	 */
 	for (i = 0; i < nchildren; i++) {
@@ -784,6 +856,7 @@ QueueRestartTwm()
 {
     XClientMessageEvent ev;
     
+printf("restart requested\n");
     ev.type = ClientMessage;
     ev.window = Scr->Root;
     ev.message_type = _XA_TWM_RESTART;
@@ -1246,3 +1319,125 @@ InternUsefulAtoms ()
     _XA_TWM_MACHINE = XInternAtom (dpy, "_TWM_MACHINE", False);
 }
 
+
+/* stolen from xwininfo */
+/*
+ * Display a set of size hints
+ */
+static void
+DisplayHints(XSizeHints *hints)
+{
+	long flags;
+
+	flags = hints->flags;
+	
+	if (flags & USPosition)
+	  printf("      User supplied location: %d, %d\n",
+		 hints->x, hints->y);
+
+	if (flags & PPosition)
+	  printf("      Program supplied location: %d, %d\n",
+		 hints->x, hints->y);
+
+	if (flags & USSize) {
+	  printf("      User supplied size: %d by %d\n",
+		 hints->width, hints->height);
+	}
+
+	if (flags & PSize)
+	  printf("      Program supplied size: %d by %d\n",
+		 hints->width, hints->height);
+
+	if (flags & PMinSize)
+	  printf("      Program supplied minimum size: %d by %d\n",
+		 hints->min_width, hints->min_height);
+
+	if (flags & PMaxSize)
+	  printf("      Program supplied maximum size: %d by %d\n",
+		 hints->max_width, hints->max_height);
+
+	if (flags & PBaseSize) {
+	  printf("      Program supplied base size: %d by %d\n",
+		 hints->base_width, hints->base_height);
+	}
+
+	if (flags & PResizeInc) {
+	  printf("      Program supplied x resize increment: %d\n",
+		 hints->width_inc);
+	  printf("      Program supplied y resize increment: %d\n",
+		 hints->height_inc);
+	  if (hints->width_inc != 0 && hints->height_inc != 0) {
+	      if (flags & USSize)
+		  printf("      User supplied size in resize increments:  %d/%d by %d/%d\n",
+			 hints->width, hints->width_inc, 
+			 hints->height, hints->height_inc);
+	      if (flags & PSize)
+		  printf("      Program supplied size in resize increments:  %d/%d by %d/%d\n",
+			 hints->width, hints->width_inc, 
+			 hints->height, hints->height_inc);
+	      if (flags & PMinSize)
+		  printf("      Program supplied minimum size in resize increments: %d/%d by %d/%d\n",
+			 hints->min_width, hints->width_inc,
+			 hints->min_height, hints->height_inc);
+	      if (flags & PBaseSize)
+		  printf("      Program supplied base size in resize increments:  %d/%d by %d/%d\n",
+			 hints->base_width, hints->width_inc, 
+			 hints->base_height, hints->height_inc);
+	  }
+        }
+
+	if (flags & PAspect) {
+	  printf("      Program supplied min aspect ratio: %d/%d\n",
+		 hints->min_aspect.x, hints->min_aspect.y);
+	  printf("      Program supplied max aspect ratio: %d/%d\n",
+		 hints->max_aspect.x, hints->max_aspect.y);
+        }
+
+	if (flags & PWinGravity) {
+	  printf("      Program supplied window gravity: %d\n",
+		hints->win_gravity);
+	}
+}
+
+/* stolen from xwininfo */
+/*
+ * print geometry
+ */
+static void
+calcgeo(Display *dpy, Drawable d, int *minxp, int *minyp, int *rxp, int *ryp)
+{
+    int rel_x, rel_y, abs_x, abs_y;
+    unsigned int width, height, border, depth;
+    Window root;
+    Window child;
+
+    if (XGetGeometry(dpy, d, &root,
+                     &rel_x, &rel_y, &width, &height, &border, &depth)) {
+
+#ifdef DEBUG
+        printf (" %ux%u+%d+%d", width, height, rel_x, rel_y);
+#endif
+	*rxp = rel_x;
+	*ryp = rel_y;
+#ifdef DEBUG
+	printf(" vorher min: %d %d", *minxp, *minyp);
+#endif
+	if ( *minxp > rel_x ) {
+		*minxp = rel_x;
+	}
+	if ( *minyp > rel_y ) {
+		*minyp = rel_y;
+	}
+#ifdef DEBUG
+	printf(" nachher min: %d %d\n", *minxp, *minyp);
+#endif
+        if (XTranslateCoordinates (dpy, d, root,
+                                   0 ,0, &abs_x, &abs_y, &child)) {
+#ifdef DEBUG
+            printf ("  +%d+%d\n", abs_x - border, abs_y - border);
+#endif
+        }
+    }
+
+}
+
