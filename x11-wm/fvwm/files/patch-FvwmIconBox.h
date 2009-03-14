--- ./modules/FvwmIconBox/FvwmIconBox.h.orig	1994-09-13 20:38:23.000000000 +0000
+++ ./modules/FvwmIconBox/FvwmIconBox.h	2009-03-11 09:42:48.000000000 +0000
@@ -15,7 +15,6 @@
 extern void   match_string(char *tline);
 extern void   Loop(void);
 extern void   ParseOptions(char *);
-extern char   *safemalloc(int length);
 extern void   change_window_name(char *str);
 extern int    My_XNextEvent(Display *dpy, XEvent *event);
 extern void   CopyString(char **dest, char *source);
