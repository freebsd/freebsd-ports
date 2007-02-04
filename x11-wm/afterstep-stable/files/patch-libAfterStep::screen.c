$FreeBSD$

--- libAfterStep/screen.c.orig	Sat Feb  3 21:34:23 2007
+++ libAfterStep/screen.c	Sat Feb  3 21:34:45 2007
@@ -135,9 +135,9 @@
 
 		if ((s = XineramaQueryScreens (dpy, &(scr->xinerama_screens_num))) != NULL)
 		{
+			static char buf[256] ; 
 			scr->xinerama_screens = safemalloc (sizeof (XRectangle) * scr->xinerama_screens_num);
 	    	asxml_var_insert("xroot.xinerama_screens_num", scr->xinerama_screens_num);
-			static char buf[256] ; 
 			for (i = 0; i < scr->xinerama_screens_num; ++i)
 			{
 				char *append_point = &buf[0]; 
