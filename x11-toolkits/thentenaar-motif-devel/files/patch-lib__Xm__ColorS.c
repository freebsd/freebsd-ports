--- lib/Xm/ColorS.c.orig	2023-02-16 00:42:34 UTC
+++ lib/Xm/ColorS.c
@@ -56,6 +56,10 @@
 
 #define SUPERCLASS ((WidgetClass) &xmManagerClassRec)
 
+#ifndef LIBDIR
+#define LIBDIR "/usr/local/lib/X11"
+#endif
+
 /************************************************************
  *       MACROS
  ************************************************************/
@@ -146,7 +150,7 @@ static XtResource resources[] =
   {
     XmNrgbFile, XmCString, XmRString,
     sizeof(String), XtOffsetOf(XmColorSelectorRec, cs.rgb_file),
-    XmRString, (XtPointer) "/usr/lib/X11/rgb.txt"
+    XmRString, (XtPointer) LIBDIR"/rgb.txt"
   },
 #endif
   {
