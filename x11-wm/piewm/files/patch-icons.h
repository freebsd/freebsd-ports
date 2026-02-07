--- icons.h.orig	Wed May 30 21:09:38 2007
+++ icons.h	Wed May 30 21:09:45 2007
@@ -53,7 +53,7 @@
 void AddIconRegion(char *geom, int grav1, int grav2, int stepx, int stepy);
 void IconDown (TwmWindow *tmp_win);
 void IconUp (TwmWindow *tmp_win);
-void PlaceIcon(TwmWindow *tmp_win, int def_x, int def_y, int *final_x, int *final_y);
+static void PlaceIcon(TwmWindow *tmp_win, int def_x, int def_y, int *final_x, int *final_y);
 
 
 
