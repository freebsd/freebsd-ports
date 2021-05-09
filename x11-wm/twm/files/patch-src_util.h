This is a cut-down version of https://bazaar.launchpad.net/~ctwm/ctwm/trunk/revision/558
which passed through vtwm and Reddit before arriving in FreeBSD ports.

--- src/util.h.orig	2020-06-14 23:58:19 UTC
+++ src/util.h
@@ -88,6 +88,8 @@ extern Status I18N_GetIconName(Display *dpy, Window wi
 extern void SetFocus(TwmWindow *tmp_win, Time time);
 extern void Bell(int type, int percent, Window win);
 
+extern XWMHints *gen_synthetic_wmhints(TwmWindow *win);
+
 extern int HotX, HotY;
 
 #define WM_BELL                 0
