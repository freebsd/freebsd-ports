--- cmd/wmii/area.c.orig	2007-11-16 13:59:15 UTC
+++ cmd/wmii/area.c
@@ -10,6 +10,30 @@
 #include <string.h>
 #include "fns.h"
 
+Display *display;
+Screen scr;
+struct Global def;
+WMScreen *screens, *screen;
+Client *client;
+View *view;
+Key *key;
+Divide *divs;
+Client c_magic;
+Client c_root;
+char buffer[8092];
+IxpServer srv;
+uint num_screens;
+uint valid_mask;
+uint num_lock_mask;
+Bool sel_screen;
+Image xor;
+Cursor cursor[CurLast];
+Image *broken;
+Bool starting;
+Bool verbose;
+char *user;
+char *execstr;
+
 static void place_frame(Frame *f);
 
 Client *
