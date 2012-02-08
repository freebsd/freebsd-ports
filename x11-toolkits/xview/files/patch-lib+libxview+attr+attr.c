--- lib/libxview/attr/attr.c.orig	2005-03-28 06:41:03.000000000 -0800
+++ lib/libxview/attr/attr.c	2012-02-02 16:15:04.864763999 -0800
@@ -91,7 +91,7 @@
    /* These two variables are used instead of the paramters so that the
       position in the lists is maintained after a recursive call. 
    */
-#if (__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 1)
+#if (__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 1) || __amd64__
    __va_copy(valist, valist1);
 #else
    valist = valist1;
