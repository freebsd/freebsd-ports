--- clients/olwm/screen.c.orig	Tue Jun 29 00:11:56 1993
+++ clients/olwm/screen.c	Fri Oct 17 15:18:34 2003
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
@@ -460,7 +467,7 @@
  * 	Construct bitmap search path as follows:
  *		$OPENWINHOME/etc/workspace/patterns
  *		$OPENWINHOME/include/X11/include/bitmaps
- *		/usr/X11/include/X11/include/bitmaps
+ *		/usr/X11R6/include/X11/include/bitmaps
  *
  * REMIND: this should be cleaned up so that it doesn't use a fixed-size 
  * array.
@@ -483,7 +490,7 @@
 	(void)sprintf(bmPath, "%s/include/X11/bitmaps",owHome);
 	bitmapSearchPath[i++] = MemNewString(bmPath);
 
-	bitmapSearchPath[i++] = MemNewString("/usr/X11/include/X11/bitmaps");
+	bitmapSearchPath[i++] = MemNewString("/usr/X11R6/include/X11/bitmaps");
 
 	bitmapSearchPath[i] = (char *)NULL;
 }
