--- clients/olwm/screen.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/screen.c	2012-02-07 18:53:41.460748331 -0800
@@ -1518,7 +1518,6 @@
 /*
  * updateScreenWorkspaceColor -- change all GC/Ginfo's that use WorkspaceColor
  */
-static
 updateScreenWorkspaceColor(dpy,scrInfo)
 	Display		*dpy;
 	ScreenInfo	*scrInfo;
@@ -1540,7 +1539,6 @@
 /*
  * updateScreenWindowColor -- change all GC/Ginfo's that use WindowColor
  */
-static
 updateScreenWindowColor(dpy,scrInfo)
 	Display		*dpy;
 	ScreenInfo	*scrInfo;
@@ -1597,7 +1595,6 @@
 /*
  * updateScreenForegroundColor -- change all GC/Ginfo's that use Foreground
  */
-static
 updateScreenForegroundColor(dpy,scrInfo)
 	Display		*dpy;
 	ScreenInfo	*scrInfo;
@@ -1630,7 +1627,6 @@
 /*
  * updateScreenBackgroundColor -- change all GC/Ginfo's that use Background
  */
-static
 updateScreenBackgroundColor(dpy,scrInfo)
 	Display		*dpy;
 	ScreenInfo	*scrInfo;
@@ -1645,7 +1641,6 @@
 /*
  * updateScreenBorderColor -- change all GC/Ginfo's that use Border
  */
-static
 updateScreenBorderColor(dpy,scrInfo)
 	Display		*dpy;
 	ScreenInfo	*scrInfo;
@@ -1761,7 +1756,6 @@
 /*
  * updateScreenGlyphFont -- change all GC/Ginfo's that use GlyphFont
  */
-static
 updateScreenGlyphFont(dpy,scrInfo)
 	Display		*dpy;
 	ScreenInfo	*scrInfo;
