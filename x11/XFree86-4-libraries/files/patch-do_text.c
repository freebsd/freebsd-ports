--- programs/x11perf/do_text.c.orig	Wed Feb 19 07:39:37 2003
+++ programs/x11perf/do_text.c	Wed Feb 19 07:39:39 2003
@@ -421,14 +421,6 @@
 	       p->font);
 	return 0;
     }
-
-    if (aafont->core)
-    {
-	printf ("FreeType font '%s' not available, benchmark omitted\n",
-		p->font);
-	XftFontClose (xp->d, aafont);
-	return 0;
-    }
     
     aadraw = XftDrawCreate (xp->d, xp->w, 
 			    DefaultVisual (xp->d, DefaultScreen (xp->d)), 
