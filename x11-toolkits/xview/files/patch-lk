--- lib/libxview/notice/notice_get.c.orig	Tue Jun 29 14:16:39 1993
+++ lib/libxview/notice/notice_get.c	Sat Jan  9 23:40:19 1999
@@ -29,9 +29,10 @@
 va_list			valist;
 {
     Notice_info	*notice = NOTICE_PRIVATE(notice_public);
-    Attr_avlist     avlist = (Attr_avlist) valist;
+    Attr_avlist     avlist;
     Xv_opaque	v = (Xv_opaque)NULL;
 
+    MAKE_AVLIST(valist, avlist);
     switch (attr)  {
     case NOTICE_LOCK_SCREEN:
         v = (Xv_opaque)notice->lock_screen;
