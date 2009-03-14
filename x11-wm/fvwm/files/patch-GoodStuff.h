--- ./modules/GoodStuff/GoodStuff.h.orig	1994-09-14 19:58:12.000000000 +0000
+++ ./modules/GoodStuff/GoodStuff.h	2009-03-11 09:42:48.000000000 +0000
@@ -13,7 +13,6 @@
 extern void   match_string(char *tline);
 extern void   Loop(void);
 extern void   ParseOptions(char *);
-extern char   *safemalloc(int length);
 extern void   change_window_name(char *str);
 extern int    My_XNextEvent(Display *dpy, XEvent *event);
 extern FVWM_INLINE void RelieveWindow(Window win,int x,int y,int w,int h,GC rGC,GC sGC);
