
$FreeBSD$

--- main.c.orig	Wed Oct 15 13:48:23 2003
+++ main.c	Sun Aug 22 22:32:26 2004
@@ -37,9 +37,7 @@
 const char	*opt_fc = DEF_FC;
 int		vdesk = KEY_TO_VDESK(XK_1);
 #endif
-#ifdef SNAP
 int		opt_snap = 0;
-#endif
 #ifdef SHAPE
 int		have_shape, shape_event;
 #endif
@@ -159,6 +157,7 @@
 					handle_shape_event((XShapeEvent *)&ev);
 				}
 #endif
+			break;
 		}
 	}
 	return 1;
