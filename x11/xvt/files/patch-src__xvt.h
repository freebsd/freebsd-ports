--- src/xvt.h.orig	2014-12-09 12:59:35.000000000 -0800
+++ src/xvt.h	2014-12-09 12:59:39.000000000 -0800
@@ -804,7 +804,7 @@
 #define xvt_Gr_ButtonRelease(x,y)	xvt_Gr_ButtonReport (r, 'R',(x),(y))
 
 #ifdef UTMP_SUPPORT
-# if !defined(XVT_UTMPX_FILE) || !defined(HAVE_STRUCT_UTMPX)
+# if !defined(HAVE_STRUCT_UTMPX)
 #  undef HAVE_UTMPX_H
 #  undef HAVE_STRUCT_UTMPX
 # endif
