--- src/Whistspectr.c.orig	2008-02-20 09:56:01.000000000 +0100
+++ src/Whistspectr.c	2008-02-20 09:57:28.000000000 +0100
@@ -52,7 +52,6 @@
 #endif
 #include <math.h>
 #include  <limits.h>
-#include <values.h>
 #include <X11/Xlib.h>
 #include<Xm/PrimitiveP.h>
 #include<Xm/DrawP.h>
@@ -574,7 +573,7 @@
                 colorpix[i++] = current->histspectr.linecolor;
         if(i)
             XFreeColors(XtDisplay(current), DefaultColormap(XtDisplay(current)
-		,DefaultScreen(XtDisplay(current))),colorpix,i,(int)NULL);
+		,DefaultScreen(XtDisplay(current))),colorpix,i,0);
         	      
 	if(newon->histspectr.xndecimals != current->histspectr.xndecimals){
 		 get_proportion(newon);		/* recalculate sizes and starting */
@@ -1029,7 +1028,7 @@
                 colorpix[i++] = cw->histspectr.linecolor;
         if(i)
             XFreeColors(XtDisplay(cw), DefaultColormap(XtDisplay(cw)
-		,DefaultScreen(XtDisplay(cw))),colorpix,i,(int)NULL);
+		,DefaultScreen(XtDisplay(cw))),colorpix,i,0);
         
 	/* XmFontListFree(cw->histspectr.font_list); */
 	XFreePixmap(XtDisplay(cw), cw->histspectr.pix);
