--- events.c.orig	1998-01-07 22:11:39.000000000 -0800
+++ events.c	2008-11-22 12:13:35.000000000 -0800
@@ -2606,8 +2606,8 @@
 		XInstallColormap(dpy, cmap->c);
 	    }
 	    cmap->state |= CM_INSTALLED;
-	    n--;
 	}
+        n--;
     }
 }
 
