--- src/util.h.orig	2020-06-14 23:58:19 UTC
+++ src/util.h
@@ -88,6 +88,8 @@ extern Status I18N_GetIconName(Display *dpy, Window wi
 extern void SetFocus(TwmWindow *tmp_win, Time time);
 extern void Bell(int type, int percent, Window win);
 
+extern XWMHints *gen_synthetic_wmhints(TwmWindow *win);
+
 extern int HotX, HotY;
 
 #define WM_BELL                 0
