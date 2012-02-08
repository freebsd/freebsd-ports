--- lib/libxview/color/cms_pblc.c.orig	2005-03-28 06:41:05.000000000 -0800
+++ lib/libxview/color/cms_pblc.c	2012-02-02 16:47:45.624915917 -0800
@@ -319,9 +319,12 @@
 /* Alpha compatibility, mbuck@debian.org */
 #if 0
     Attr_avlist     	avlist = (Attr_avlist) args;
+#else
+    Attr_avlist       avlist;
 #endif
     int			cms_status = 0;
 
+    MAKE_AVLIST(args, avlist);
     switch (attr) {
       case CMS_PIXEL: {
 	  unsigned long    index;
