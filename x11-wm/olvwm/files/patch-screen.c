--- screen.c.orig	2013-09-17 21:38:07.462238988 -0700
+++ screen.c	2013-09-17 21:43:56.890844306 -0700
@@ -66,6 +66,13 @@
  *-------------------------------------------------------------------------*/
 List	*ScreenInfoList;			/* List of managed screens */
 extern	Bool BoolString();
+static	updateScreenWorkspaceColor();
+static	updateScreenWindowColor();
+static	updateScreenForegroundColor();
+static	updateScreenBackgroundColor();
+static	updateScreenBorderColor();
+static	updateScreenInputFocusColor();
+static	updateScreenGlyphFont();
 
 /*-------------------------------------------------------------------------
  *	Local Data
@@ -282,6 +289,7 @@
 		     	case PseudoColor:
 			case GrayScale:
 		     	case DirectColor:
+			case TrueColor:
 		    		return True;
 				/*NOTREACHED*/
 		    		break;
@@ -523,7 +531,7 @@
  *      Construct bitmap search path as follows:
  *	      $OPENWINHOME/etc/workspace/patterns
  *	      $OPENWINHOME/include/X11/include/bitmaps
- *	      /usr/X11/include/X11/include/bitmaps
+ *	      /usr/X11R6/include/X11/include/bitmaps
  *
  * REMIND: this should be cleaned up so that it doesn't use a fixed-size
  * array.
@@ -546,7 +554,7 @@
 	(void)sprintf(bmPath, "%s/include/X11/bitmaps",owHome);
 	bitmapSearchPath[i++] = MemNewString(bmPath);
 
-	bitmapSearchPath[i++] = MemNewString("/usr/X11/include/X11/bitmaps");
+	bitmapSearchPath[i++] = MemNewString("/usr/X11R6/include/X11/bitmaps");
 	bitmapSearchPath[i] = (char *)NULL;
 }
 
@@ -2431,7 +2439,7 @@
 	if (!geom)
 	    geom = GRV.VirtualGeometry;
 	if (!geom || !*geom)
-	    return;
+	    return 0;
 	if (scrInfo->vdm->resources->geometry)
 	    free(scrInfo->vdm->resources->geometry);
 	scrInfo->vdm->resources->geometry = strdup(geom);
@@ -2451,7 +2459,7 @@
 	if (!name)
 	    name = GRV.VirtualBackgroundMap;
 	if (!name || !*name)
-	    return;
+	    return 0;
 	if (scrInfo->vdm->resources->background)
 	    free(scrInfo->vdm->resources->background);
 	scrInfo->vdm->resources->background = strdup(name);
@@ -2479,7 +2487,7 @@
 	ScreenInfo	*scrInfo;
 {
 	if (!scrInfo->vdm->resources->background)
-	    return;
+	    return 0;
 	UpdateScreenVirtualMap(dpy,scrInfo);
 }
 
