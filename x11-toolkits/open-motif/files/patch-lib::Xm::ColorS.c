--- lib/Xm/ColorS.c.orig	Mon Mar 24 09:01:49 2003
+++ lib/Xm/ColorS.c	Mon Mar 24 09:02:44 2003
@@ -107,6 +107,10 @@
 
 #define	offset(field) XmPartOffset(XmColorSelector, field)
 	
+#ifndef LIBDIR
+#define LIBDIR "/usr/lib/X11"
+#endif
+
 static XmPartResource resources[] = {
     { XmNcolorMode, XmCColorMode, XmRXmColorMode, sizeof(XmColorMode),
       offset(color_mode), XmRImmediate, (XtPointer) XmScaleMode },
@@ -117,7 +121,7 @@
       offset(rgb_file), XmRString, (XtPointer) "sys$manager:decw$rgb.dat" },
 #else
     { XmNrgbFile, XmCString, XmRString, sizeof(String),
-      offset(rgb_file), XmRString, (XtPointer) "/usr/lib/X11/rgb.txt" },
+      offset(rgb_file), XmRString, (XtPointer) LIBDIR"/rgb.txt" },
 #endif
     { XmNmarginWidth, XmCMargin, XmRHorizontalDimension,sizeof(Dimension),
       offset(margin_width), XmRImmediate, (XtPointer) 2 },
