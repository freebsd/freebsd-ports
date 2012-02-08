--- lib/libxview/base/xv.c.orig	2005-03-28 06:41:49.000000000 -0800
+++ lib/libxview/base/xv.c	2012-02-02 16:22:12.711340868 -0800
@@ -556,7 +556,7 @@
 	case XV_KEY_DATA:
 	case XV_IS_SUBTYPE_OF:
 	    status = XV_OK;
-#if (__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 1)
+#if (__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 1) || __amd64__
 	    __va_copy(args, args_save);
 #else
 	    args = args_save;
@@ -579,7 +579,7 @@
 	 * Go to the beginning of the varargs list every time to insure each
          * pkg gets the start of the  varargs.
 	 */
-#if (__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 1)
+#if (__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 1) || __amd64__
 	__va_copy(args, args_save);
 #else
         args = args_save;
