--- src/rxvt.h
+++ src/rxvt.h
@@ -804,7 +804,7 @@
 #define rxvt_Gr_ButtonRelease(x,y)	rxvt_Gr_ButtonReport (r, 'R',(x),(y))
 
 #ifdef UTMP_SUPPORT
-# if !defined(RXVT_UTMPX_FILE) || !defined(HAVE_STRUCT_UTMPX)
+# if !defined(HAVE_STRUCT_UTMPX)
 #  undef HAVE_UTMPX_H
 #  undef HAVE_STRUCT_UTMPX
 # endif
