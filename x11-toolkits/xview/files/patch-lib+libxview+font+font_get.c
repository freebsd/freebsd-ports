--- lib/libxview/font/font_get.c.orig	2005-03-28 06:41:44.000000000 -0800
+++ lib/libxview/font/font_get.c	2012-02-02 17:10:02.725435117 -0800
@@ -47,6 +47,11 @@
 #if 0
     Attr_avlist     avlist = (Attr_avlist) args;
 #endif
+#ifdef __FreeBSD__
+    Attr_avlist     avlist;
+
+    MAKE_AVLIST(args, avlist);
+#endif
 
 #ifdef OW_I18N
     if (font->type == FONT_TYPE_TEXT)  {
