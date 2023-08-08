--- src/strings.c.orig	2005-03-21 00:42:08 UTC
+++ src/strings.c
@@ -44,6 +44,7 @@
 
 #ifdef HAVE_WCHAR_H
 /* EXTPROTO */
+#if _FreeBSD_version >= 500000
 char*
 rxvt_wcstombs (const wchar_t* str, int len)
 {
@@ -70,6 +71,7 @@ rxvt_wcstombs (const wchar_t* str, int len)
 
 	return r;
 }
+#endif
 
 
 /* EXTPROTO */
