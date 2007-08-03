--- clients/olwm/screen.c.orig	1993-06-29 07:11:56.000000000 +0200
+++ clients/olwm/screen.c	2007-08-03 14:58:43.000000000 +0200
@@ -39,6 +39,8 @@
 #include "iconimage.h"
 #include "iconmask.h"
 
+static updateScreenBackgroundColor(Display *dpy, ScreenInfo *scrInfo);
+
 /*-------------------------------------------------------------------------
  *	Default Constants
  *-------------------------------------------------------------------------*/
@@ -111,6 +113,12 @@
 static XrmQuark stippledRubberBandsCQ;
 static XrmQuark stippledRubberBandsIQ;
 
+static updateScreenWorkspaceColor();
+static updateScreenWindowColor();
+static updateScreenForegroundColor();
+static updateScreenBackGroundColor();
+static updateScreenBorderColor();
+static updateScreenGlyphFont();
 
 /*-------------------------------------------------------------------------
  *	Local Functions
@@ -214,6 +222,7 @@
 		     	case PseudoColor:
 			case GrayScale:
 		     	case DirectColor:
+			case TrueColor:
 		    		return True;
 				/*NOTREACHED*/
 		    		break;
