$FreeBSD$

--- src/misc.h.orig	Sun May 26 16:45:09 2002
+++ src/misc.h	Wed Sep 25 13:24:24 2002
@@ -52,5 +52,5 @@ int max_xstringChars(wm *w, int *width, 
 int max_xstringChars(wm *w, int *width, char *txt, XFontStruct* font_info);
 #endif
 void scale_icon(Client *c);
-#endif _MISC_H_
+#endif /* _MISC_H_ */
 
