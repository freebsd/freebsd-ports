--- goodies/fspanel/fspanel.h.orig	2013-09-26 17:22:27.000000000 +0200
+++ goodies/fspanel/fspanel.h	2013-09-26 17:22:37.000000000 +0200
@@ -55,7 +55,7 @@
 
 void set_bottom_strut();
 void set_top_strut();
-void *get_prop_data (Window win, Atom prop, Atom type, int *items);
+unsigned long *get_prop_data (Window win, Atom prop, Atom type, int *items);
 void set_foreground (int index);
 void draw_line (taskbar *tb, int x, int y, int a, int b);
 void fill_rect (taskbar *tb, int x, int y, int a, int b);
