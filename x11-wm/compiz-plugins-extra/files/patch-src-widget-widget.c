--- src/widget/widget.c.orig	2007-08-24 18:24:42.000000000 -0400
+++ src/widget/widget.c	2007-08-24 18:25:02.000000000 -0400
@@ -68,7 +68,6 @@
     PreparePaintScreenProc preparePaintScreen;
     DonePaintScreenProc    donePaintScreen;
     PaintWindowProc        paintWindow;
-    WindowAddNotifyProc    windowAddNotify;
 
     WidgetState state;
 
@@ -82,7 +81,9 @@
 {
     Bool                isWidget;
     Bool                wasUnmapped;
+    CompWindow          *parentWidget;
     CompTimeoutHandle   matchUpdateHandle;
+    CompTimeoutHandle   inferiorUpdateHandle;
     WidgetPropertyState propertyState;
 } WidgetWindow;
 
@@ -106,6 +107,41 @@
 		       GET_WIDGET_SCREEN  (w->screen,            \
 		       GET_WIDGET_DISPLAY (w->screen->display)))
 
+static void
+widgetUpdateTreeStatus (CompWindow *w)
+{
+    CompWindow   *p;
+    WidgetWindow *pww;
+
+    WIDGET_SCREEN (w->screen);
+
+    /* first clear out every reference to our window */
+    for (p = w->screen->windows; p; p = p->next)
+    {
+	pww = GET_WIDGET_WINDOW (p, ws);
+	if (pww->parentWidget == w)
+	    pww->parentWidget = NULL;
+    }
+
+    for (p = w->screen->windows; p; p = p->next)
+    {
+	Window clientLeader;
+
+	if (p->attrib.override_redirect)
+	    clientLeader = getClientLeader (p);
+	else
+	    clientLeader = p->clientLeader;
+
+	if ((clientLeader == w->clientLeader) && (w->id != p->id))
+	{
+	    WIDGET_SCREEN (w->screen);
+
+	    pww = GET_WIDGET_WINDOW (p, ws);
+	    pww->parentWidget = w;
+	}
+    }
+}
+
 static Bool
 widgetUpdateWidgetStatus (CompWindow *w)
 {
@@ -131,7 +167,7 @@
     return retval;
 }
 
-static void
+static Bool
 widgetUpdateWidgetPropertyState (CompWindow *w)
 {
     CompDisplay   *d = w->screen->display;
@@ -144,7 +180,7 @@
     WIDGET_WINDOW (w);
 
     result = XGetWindowProperty (d->display, w->id, wd->compizWidgetAtom,
-				 0, 1L, FALSE, XA_CARDINAL, &retType,
+				 0, 1L, FALSE, AnyPropertyType, &retType,
 				 &format, &nitems, &remain, &data);
 
     if (result == Success && nitems && data)
@@ -159,7 +195,7 @@
     else
 	ww->propertyState = PropertyNotSet;
 
-    widgetUpdateWidgetStatus (w);
+    return widgetUpdateWidgetStatus (w);
 }
 
 static void
@@ -271,6 +307,8 @@
 		map = !ww->isWidget || (ws->state != StateOff);
 		widgetUpdateWidgetMapState (w, map);
 
+		widgetUpdateTreeStatus (w);
+
 		(*d->matchPropertyChanged) (d, w);
 	    }
     }
@@ -295,19 +333,13 @@
 
 	switch (ws->state) {
 	case StateOff:
+	case StateFadeOut:
 	    widgetSetWidgetLayerMapState (s, TRUE);
 	    ws->fadeTime = 1000.0f * widgetGetFadeTime (s);
 	    ws->state = StateFadeIn;
 	    break;
-	case StateFadeIn:
-	    ws->fadeTime = (1000.0f * widgetGetFadeTime (s)) - ws->fadeTime;
-	    ws->state = StateFadeOut;
-	    break;
-	case StateFadeOut:
-	    ws->fadeTime = (1000.0f * widgetGetFadeTime (s)) - ws->fadeTime;
-	    ws->state = StateFadeIn;
-	    break;
 	case StateOn:
+	case StateFadeIn:
 	    widgetSetWidgetLayerMapState (s, FALSE);
 	    ws->fadeTime = 1000.0f * widgetGetFadeTime (s);
 	    ws->state = StateFadeOut;
@@ -345,8 +377,33 @@
 	    w = findWindowAtDisplay (d, event->xproperty.window);
 	    if (w)
 	    {
-		widgetUpdateWidgetPropertyState (w);
-		(*d->matchPropertyChanged) (d, w);
+		if (widgetUpdateWidgetPropertyState (w))
+		{
+		    Bool map;
+
+		    WIDGET_SCREEN (w->screen);
+		    WIDGET_WINDOW (w);
+
+		    map = !ww->isWidget || (ws->state != StateOff);
+		    widgetUpdateWidgetMapState (w, map);
+		    widgetUpdateTreeStatus (w);
+		    (*d->matchPropertyChanged) (d, w);
+		}
+	    }
+	}
+	else if (event->xproperty.atom == d->wmClientLeaderAtom)
+	{
+	    CompWindow *w;
+
+	    w = findWindowAtDisplay (d, event->xproperty.window);
+	    if (w)
+	    {
+		WIDGET_WINDOW (w);
+
+		if (ww->isWidget)
+		    widgetUpdateTreeStatus (w);
+		else if (ww->parentWidget)
+		    widgetUpdateTreeStatus (ww->parentWidget);
 	    }
 	}
 	break;
@@ -368,7 +425,7 @@
 		    {
 			WIDGET_WINDOW (w);
 
-			if (!ww->isWidget)
+			if (!ww->isWidget && !ww->parentWidget)
 			{
 			    CompOption o;
 
@@ -409,12 +466,54 @@
     WIDGET_WINDOW (w);
 
     if (widgetUpdateWidgetStatus (w))
+    {
+	widgetUpdateTreeStatus (w);
 	(*w->screen->display->matchPropertyChanged) (w->screen->display, w);
+    }
 
     ww->matchUpdateHandle = 0;
     return FALSE;
 }
 
+static Bool
+widgetUpdateInferiors (void *closure)
+{
+    CompWindow *w = (CompWindow *) closure;
+    Window     clientLeader;
+
+    WIDGET_WINDOW (w);
+
+    if (w->attrib.override_redirect)
+	clientLeader = getClientLeader (w);
+    else
+	clientLeader = w->clientLeader;
+
+    if (ww->isWidget)
+    {
+	widgetUpdateTreeStatus (w);
+    }
+    else if (clientLeader)
+    {
+	CompWindow *lw;
+
+	lw = findWindowAtScreen (w->screen, clientLeader);
+	if (lw)
+	{
+	    WidgetWindow *lww;
+
+	    WIDGET_SCREEN (w->screen);
+	    lww = GET_WIDGET_WINDOW (lw, ws);
+
+	    if (lww->isWidget)
+		ww->parentWidget = lw;
+	    else if (lww->parentWidget)
+		ww->parentWidget = lww->parentWidget;
+	}
+    }
+
+    ww->inferiorUpdateHandle = 0;
+    return FALSE;
+}
 
 static void
 widgetMatchPropertyChanged (CompDisplay *d,
@@ -435,20 +534,6 @@
     WRAP (wd, d, matchPropertyChanged, widgetMatchPropertyChanged);
 }
 
-static void
-widgetWindowAddNotify (CompWindow *w)
-{
-    WIDGET_SCREEN (w->screen);
-    WIDGET_WINDOW (w);
-
-    if (ww->isWidget)
-	widgetUpdateWidgetMapState (w, (ws->state != StateOff));
-
-    UNWRAP (ws, w->screen, windowAddNotify);
-    (*w->screen->windowAddNotify) (w);
-    WRAP (ws, w->screen, windowAddNotify, widgetWindowAddNotify);
-}
-
 static Bool
 widgetPaintWindow (CompWindow              *w,
 		   const WindowPaintAttrib *attrib,
@@ -478,7 +563,7 @@
 	    fadeProgress = 1.0f - fadeProgress;
 	}
 
-	if (!ww->isWidget)
+	if (!ww->isWidget && !ww->parentWidget)
 	{
 	    float progress;
 
@@ -572,6 +657,7 @@
 		    map = !ww->isWidget || (ws->state != StateOff);
 		    widgetUpdateWidgetMapState (w, map);
 
+		    widgetUpdateTreeStatus (w);
 		    (*s->display->matchPropertyChanged) (s->display, w);
 		}
 	}
@@ -700,12 +786,18 @@
         return FALSE;
 
     ww->isWidget = FALSE;
+    ww->parentWidget = NULL;
     ww->wasUnmapped = FALSE;
     ww->matchUpdateHandle = 0;
+    ww->inferiorUpdateHandle = 0;
 
     w->privates[ws->windowPrivateIndex].ptr = ww;
 
-    widgetUpdateWidgetPropertyState (w);
+    if (widgetUpdateWidgetPropertyState (w))
+	widgetUpdateWidgetMapState (w, (ws->state != StateOff));
+
+    ww->inferiorUpdateHandle = compAddTimeout (0, widgetUpdateInferiors,
+					       (void *) w);
 
     return TRUE;
 }
@@ -722,6 +814,9 @@
     if (ww->matchUpdateHandle)
 	compRemoveTimeout (ww->matchUpdateHandle);
 
+    if (ww->inferiorUpdateHandle)
+	compRemoveTimeout (ww->inferiorUpdateHandle);
+
     free (ww);
 }
 
