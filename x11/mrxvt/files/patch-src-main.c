--- src/main.c.orig	Fri Jul 22 19:42:38 2005
+++ src/main.c	Fri Jul 22 19:43:03 2005
@@ -1568,7 +1568,7 @@
 void
 rxvt_set_utf8_property (rxvt_t* r, Atom prop, Window win, const char* str)
 {
-#ifdef HAVE_WCHAR_H
+#ifdef HAVE_WCHAR_H && _FreeBSD_version >= 500000
 	wchar_t*	ws = rxvt_mbstowcs (str);
 	char*		s = rxvt_wcstoutf8 (ws);
 
