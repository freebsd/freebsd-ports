--- src/strings.c.orig	Fri Jul 22 19:49:43 2005
+++ src/strings.c	Fri Jul 22 19:50:40 2005
@@ -44,6 +44,7 @@
 
 #ifdef HAVE_WCHAR_H
 /* EXTPROTO */
+#if _FreeBSD_version >= 500000
 char*
 rxvt_wcstombs (const wchar_t* str, int len)
 {
@@ -70,6 +71,7 @@
 
 	return r;
 }
+#endif
 
 
 /* EXTPROTO */
