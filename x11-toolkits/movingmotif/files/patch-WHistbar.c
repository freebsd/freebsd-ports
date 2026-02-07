--- src/WHistbar.c.orig	2008-02-20 09:44:34.000000000 +0100
+++ src/WHistbar.c	2008-02-20 09:48:53.000000000 +0100
@@ -1140,7 +1140,7 @@
 	    	colorpix[0] = cw->histbar.bars[ID].color;
 	    	colorpix[1] = cw->histbar.bars[ID].shadecolor;	
 		XFreeColors(XtDisplay(cw), DefaultColormap(XtDisplay(cw)
-		,DefaultScreen(XtDisplay(cw))),colorpix,2,(int)NULL);		
+		,DefaultScreen(XtDisplay(cw))),colorpix,2,0);		
 
 	    }
 	}
@@ -1930,7 +1930,7 @@
  	colorpix[0] = cw->histbar.bars[ID].color;
 	colorpix[1] = cw->histbar.bars[ID].shadecolor;	
 	XFreeColors(XtDisplay(w), DefaultColormap(XtDisplay(w)
-		,DefaultScreen(XtDisplay(w))),colorpix,2,(int)NULL);		
+		,DefaultScreen(XtDisplay(w))),colorpix,2,0);		
 	cw->histbar.bars[ID].color = color;
 	Gethistbarcolours (cw , &(cw->histbar.bars[ID]) );
 	
