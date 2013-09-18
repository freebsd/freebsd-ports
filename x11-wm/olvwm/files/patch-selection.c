--- selection.c.orig	2013-09-17 21:38:07.442239399 -0700
+++ selection.c	2013-09-17 21:45:20.241114850 -0700
@@ -318,13 +318,13 @@
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
 
