--- lib/Xm/ColorS.c.orig	2005-12-17 16:54:03.000000000 +0300
+++ lib/Xm/ColorS.c	2011-01-16 00:48:05.000000000 +0300
@@ -41,6 +41,10 @@
 
 #define SUPERCLASS ((WidgetClass) &xmManagerClassRec)
 
+#ifndef LIBDIR
+#define LIBDIR "/usr/local/lib/X11"
+#endif
+
 /************************************************************
  *       MACROS
  ************************************************************/
@@ -131,7 +135,7 @@
   {
     XmNrgbFile, XmCString, XmRString,
     sizeof(String), XtOffsetOf(XmColorSelectorRec, cs.rgb_file),
-    XmRString, (XtPointer) "/usr/lib/X11/rgb.txt"
+    XmRString, (XtPointer) LIBDIR"/rgb.txt"
   },
 #endif
   {
