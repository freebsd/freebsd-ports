--- lib/libxview/notice/notice_get.c.orig	2005-03-28 06:41:08.000000000 -0800
+++ lib/libxview/notice/notice_get.c	2012-02-02 20:44:18.306259052 -0800
@@ -32,9 +32,12 @@
 /* Alpha compatibility, mbuck@debian.org */
 #if 0
     Attr_avlist     avlist = (Attr_avlist) valist;
+#else
+    Attr_avlist     avlist;
 #endif
     Xv_opaque	v = (Xv_opaque)NULL;
 
+    MAKE_AVLIST(valist, avlist);
     switch (attr)  {
     case NOTICE_LOCK_SCREEN:
         v = (Xv_opaque)notice->lock_screen;
