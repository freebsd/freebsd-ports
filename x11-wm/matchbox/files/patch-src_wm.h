$FreeBSD$

--- src/wm.h.orig	Mon Jun 24 08:27:44 2002
+++ src/wm.h	Wed Sep 25 13:23:43 2002
@@ -86,4 +86,4 @@ void wm_gravitate(Client *c, int multipl
 void wm_init_existing(Wm *w);
 int wm_total_dock_height(Client *c);
 void wm_toggle_desktop(Wm *w);
-#endif _WM_H_
+#endif /* _WM_H_ */
