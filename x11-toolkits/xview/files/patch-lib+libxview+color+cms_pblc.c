--- lib/libxview/color/cms_pblc.c.orig	Mon Sep 29 00:02:28 2003
+++ lib/libxview/color/cms_pblc.c	Mon Sep 29 00:02:28 2003
@@ -316,9 +316,10 @@
 {
     Cms_info		*cms = CMS_PRIVATE(cms_public);
     Xv_opaque		value;
-    Attr_avlist     	avlist = (Attr_avlist) args;
+    Attr_avlist     	avlist;
     int			cms_status = 0;
 
+    MAKE_AVLIST(args, avlist);
     switch (attr) {
       case CMS_PIXEL: {
 	  unsigned long    index;
