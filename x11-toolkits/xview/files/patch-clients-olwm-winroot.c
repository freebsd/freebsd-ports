--- clients/olwm/winroot.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/winroot.c	2013-09-17 23:12:58.282771195 -0700
@@ -189,7 +189,7 @@
 	WinRoot		*winInfo;
 {
 	if (pEvent->xcrossing.detail == NotifyNonlinearVirtual)
-	    return;
+	    return 0;
 
 	ColorWindowCrossing(dpy, pEvent, winInfo);
 
@@ -283,7 +283,7 @@
 	int			(*selectFunc)();
 
 	if (!pEvent->xmotion.same_screen)
-	    return;
+	    return 0;
 
 	/* If the user hasn't moved more than the threshold
 	 * amount, break out of here.  REMIND  Also, if we get a 
@@ -296,9 +296,9 @@
 	     GRV.MoveThreshold) &&
 	    (ABS(pEvent->xmotion.y - winInfo->buttonPressEvent.xbutton.y) < 
 	     GRV.MoveThreshold))
-	    return;
+	    return 0;
 	if (pEvent->xmotion.state == 0)
-	   return;
+	   return 0;
 	
 	/*
 	 * On Select: Clear existing selected clients and add new ones
@@ -335,7 +335,7 @@
 	WinRoot		*winInfo;
 {
 	if (!AllButtonsUp(pEvent))
-	    return;
+	    return 0;
 
 	/*
 	 * This only happens if we did NOT get a motion notify
@@ -384,7 +384,7 @@
 		    pEvent->xbutton.time)))
 	    {
 		PropagatePressEventToChild(dpy, pEvent, child);
-		return;
+		return 0;
 	    }
 
 	    /*
@@ -453,7 +453,7 @@
 	if ((pEvent->xproperty.atom != XA_RESOURCE_MANAGER)
 	     || (pEvent->xproperty.state != PropertyNewValue))
 	{
-	    return;
+	    return 0;
 	}
 
 	UpdateGlobals(dpy);
