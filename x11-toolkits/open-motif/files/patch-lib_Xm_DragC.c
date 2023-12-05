--- lib/Xm/DragC.c.orig	2017-08-16 17:38:43.000000000 -0700
+++ lib/Xm/DragC.c	2023-12-04 15:58:26.431030000 -0800
@@ -846,35 +846,18 @@
   if (newStyle != oldStyle) 
     {
       /*
-       * If we're not still waiting to hear from the window manager,
-       * and we're not running dynamic, then we can grab.
+       * If we are in pixmap mode, release the grab.
        */
-      if ((dc->drag.trackingMode != XmDRAG_TRACK_WM_QUERY_PENDING) &&
-	  (newStyle != XmDRAG_DYNAMIC) &&
-	  (initiator != XmDRAG_DYNAMIC) &&
-	  (initiator != XmDRAG_PREFER_DYNAMIC))
+      if (dc->drag.serverGrabbed)
 	{
-	  if (!dc->drag.serverGrabbed)
-	    {
-	      XGrabServer(XtDisplay(dc));
-	      dc->drag.serverGrabbed = True;
-	      XtSetArg(args[0], XmNdragOverMode, XmPIXMAP);
-	      XtSetValues( (Widget)dc->drag.curDragOver, args, 1);
-	    }
+	  XUngrabServer(XtDisplay(dc));
+	  dc->drag.serverGrabbed = False;
+	  if (xmDisplay -> display.displayHasShapeExtension)
+	    XtSetArg(args[0], XmNdragOverMode, XmDRAG_WINDOW);
+	  else
+	    XtSetArg(args[0], XmNdragOverMode, XmCURSOR);
+	  XtSetValues( (Widget)dc->drag.curDragOver, args, 1);
 	}
-      else
-	{
-	  if (dc->drag.serverGrabbed)
-	    {
-	      XUngrabServer(XtDisplay(dc));
-	      dc->drag.serverGrabbed = False;
-	      if (xmDisplay -> display.displayHasShapeExtension) 
-		XtSetArg(args[0], XmNdragOverMode, XmDRAG_WINDOW);
-	      else
-		XtSetArg(args[0], XmNdragOverMode, XmCURSOR);
-	      XtSetValues( (Widget)dc->drag.curDragOver, args, 1);
-	    }
-	}
     }
 }
 
@@ -1687,23 +1670,13 @@
   /* Build a new one */
   i = 0;
   /*
-   * If this is the first call, tracking mode will be querypending
-   * and we have to come up in cursor mode.  Otherwise, we come up
-   * in cursor for dynamic and pixmap for preregister.
+   * Always come up in window mode (or cursor if SHAPE is not available).
    */
-  if ((dc->drag.trackingMode == XmDRAG_TRACK_WM_QUERY_PENDING) ||
-      (dc->drag.activeProtocolStyle == XmDRAG_DYNAMIC))
-    {
-      if (dpy -> display.displayHasShapeExtension) 
-	XtSetArg(args[i], XmNdragOverMode, XmDRAG_WINDOW);
-      else
-	XtSetArg(args[i], XmNdragOverMode, XmCURSOR); 
-      i++;
-    }
+  if (dpy -> display.displayHasShapeExtension)
+    XtSetArg(args[i], XmNdragOverMode, XmDRAG_WINDOW);
   else
-    {
-      XtSetArg(args[i], XmNdragOverMode, XmPIXMAP); i++;
-    }
+    XtSetArg(args[i], XmNdragOverMode, XmCURSOR);
+  i++;
   
   XtSetArg(args[i], XmNhotX, dc->core.x); i++;
   XtSetArg(args[i], XmNhotY, dc->core.y); i++;
