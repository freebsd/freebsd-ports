--- fvwm/functions.c.orig	1994-11-15 14:18:26 UTC
+++ fvwm/functions.c
@@ -52,7 +52,7 @@
 extern XEvent Event;
 extern FvwmWindow *Tmp_win;
 extern int menuFromFrameOrWindowOrTitlebar;
-extern DoHandlePageing;
+extern Bool DoHandlePageing;
 
 extern char **g_argv;
 
@@ -1643,7 +1643,7 @@ void MapIt(FvwmWindow *t)
 
 void QuickRestart(void)
 {
-  extern char *m4_options;
+  extern char m4_options[];
   extern char *display_name;
   int i;
   FvwmWindow *tmp,*next;  
