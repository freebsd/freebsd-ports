--- libs/Ficonv.c.orig	2011-08-16 09:05:53.000000000 +0200
+++ libs/Ficonv.c	2014-03-29 17:17:54.000000000 +0100
@@ -36,7 +36,7 @@
 #if defined(USE_LIBICONV) && !defined (_LIBICONV_H)
 #error libiconv in use but included iconv.h not from libiconv
 #endif
-#if !defined(USE_LIBICONV) && defined (_LIBICONV_H)
+#if !defined(USE_LIBICONV) && defined (_LIBICONV_H) && !defined (LIBICONV_PLUG)
 #error libiconv not in use but included iconv.h is from libiconv
 #endif
 #endif /* FiconvSupport */
