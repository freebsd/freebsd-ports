--- lib/libxview/attr/attr.c.orig	Wed May  5 15:36:36 2004
+++ lib/libxview/attr/attr.c	Wed May  5 15:37:13 2004
@@ -91,7 +91,12 @@
    /* These two variables are used instead of the paramters so that the
       position in the lists is maintained after a recursive call. 
    */
+
+#ifdef __amd64__
+   va_copy(valist,valist1);
+#else
    valist = valist1;
+#endif
    avlist = avlist1;
 
    if( !avlist )
