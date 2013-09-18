--- winroot.c.orig	2013-09-17 21:38:07.482238656 -0700
+++ winroot.c	2013-09-17 22:13:41.361407148 -0700
@@ -197,7 +197,7 @@
 	WinRoot		*winInfo;
 {
         if (pEvent->xcrossing.detail == NotifyNonlinearVirtual)
-            return;
+            return 0;
 
 	ColorWindowCrossing(dpy, pEvent, winInfo);
 
@@ -291,7 +291,7 @@
 	int			(*selectFunc)();
 
 	if (!pEvent->xmotion.same_screen)
-	    return;
+	    return 0;
 
 	/* If the user hasn't moved more than the threshold
 	 * amount, break out of here.  REMIND  Also, if we get a 
@@ -304,9 +304,9 @@
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
@@ -343,7 +343,7 @@
 	WinRoot		*winInfo;
 {
 	if (!AllButtonsUp(pEvent))
-	    return;
+	    return 0;
 
 	/*
 	 * This only happens if we did NOT get a motion notify
@@ -389,7 +389,7 @@
 		    pEvent->xbutton.time)))
 	    {
 		PropagatePressEventToChild(dpy, pEvent, child);
-		return;
+		return 0;
 	    }
 
 	    /*
@@ -457,7 +457,7 @@
 	 */
 	if ((pEvent->xproperty.atom != XA_RESOURCE_MANAGER) 
 	     || (pEvent->xproperty.state != PropertyNewValue))
-		return;
+		return 0;
 
 	UpdateGlobals(dpy);
 }
