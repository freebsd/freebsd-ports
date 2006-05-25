--- lib/libxview/sel/seln.c.orig	2006-01-04 10:33:29.000000000 +0000
+++ lib/libxview/sel/seln.c
@@ -69,7 +69,6 @@ selection_get(sel_read, window)
     FILE           *file;
     int             c;
     int             n;
-    extern          errno;
 
     *sel = selnull;
     (void) win_lockdata(window);
