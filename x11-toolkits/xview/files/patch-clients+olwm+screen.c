--- clients/olwm/screen.c.orig	Tue Jun 29 00:11:56 1993
+++ clients/olwm/screen.c	Sat Jun 30 19:34:43 2007
@@ -111,6 +111,12 @@
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
@@ -214,6 +220,7 @@
 		     	case PseudoColor:
 			case GrayScale:
 		     	case DirectColor:
+			case TrueColor:
 		    		return True;
 				/*NOTREACHED*/
 		    		break;
