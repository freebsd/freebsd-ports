$FreeBSD$

main.c: In function `main':
main.c:92: error: `opt_snap' undeclared (first use in this function)

--- main.c.orig	Wed Oct 15 11:48:23 2003
+++ main.c	Fri Oct 24 05:09:42 2003
@@ -37,9 +37,7 @@ int		opt_bw = DEF_BW;
 const char	*opt_fc = DEF_FC;
 int		vdesk = KEY_TO_VDESK(XK_1);
 #endif
-#ifdef SNAP
 int		opt_snap = 0;
-#endif
 #ifdef SHAPE
 int		have_shape, shape_event;
 #endif
