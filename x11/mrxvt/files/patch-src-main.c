--- src/main.c.orig	2005-08-31 05:30:41 UTC
+++ src/main.c
@@ -1568,7 +1568,7 @@ rxvt_set_utf8_property (rxvt_t* r, Atom prop, Window w
 void
 rxvt_set_utf8_property (rxvt_t* r, Atom prop, Window win, const char* str)
 {
-#ifdef HAVE_WCHAR_H
+#ifdef HAVE_WCHAR_H && _FreeBSD_version >= 500000
 	wchar_t*	ws = rxvt_mbstowcs (str);
 	char*		s = rxvt_wcstoutf8 (ws);
 
