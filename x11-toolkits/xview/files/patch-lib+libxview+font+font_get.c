--- lib/libxview/font/font_get.c.orig	Tue Jun 29 14:15:00 1993
+++ lib/libxview/font/font_get.c	Sat Jan  9 23:35:51 1999
@@ -43,7 +43,9 @@
     XFontStruct		*x_font_info = (XFontStruct *)font->x_font_info;
     Xv_opaque       v;
     int             attr_is_char_width = 0;
-    Attr_avlist     avlist = (Attr_avlist) args;
+    Attr_avlist     avlist;
+
+    MAKE_AVLIST(args, avlist);
 
 #ifdef OW_I18N
     if (font->type == FONT_TYPE_TEXT)  {
