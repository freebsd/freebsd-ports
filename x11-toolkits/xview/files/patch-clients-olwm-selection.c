--- clients/olwm/selection.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/selection.c	2013-09-17 22:55:40.832118661 -0700
@@ -316,13 +316,13 @@
 		XSetSelectionOwner(cli->dpy, XA_PRIMARY,
 				   NoFocusWin, timestamp);
 		if (NoFocusWin != XGetSelectionOwner(cli->dpy, XA_PRIMARY))
-		    return;
+		    return 0;
 	} else {
 		/* First look to see if window is already listed. */
 		for(tc = ListEnum(&l); tc != NULL; tc = ListEnum(&l))
 		{
 			if (tc == cli)
-				return;
+				return 0;
 		}
 	}
 
