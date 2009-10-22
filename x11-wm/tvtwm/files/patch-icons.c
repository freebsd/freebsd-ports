--- icons.c-orig	2009-10-10 20:22:14.000000000 +0200
+++ icons.c	2009-10-10 20:22:13.000000000 +0200
@@ -233,10 +233,12 @@
 	*final_x = ie->x + (ie->w - iconWidth (tmp_win)) / 2;
 	*final_y = ie->y + (ie->h - iconHeight (tmp_win)) / 2;
     } else {
+/*
 	if (tmp_win->root == Scr->VirtualDesktop) {
 	    def_x += Scr->vdtPositionX;
 	    def_y += Scr->vdtPositionY;
 	}
+*/
 	*final_x = def_x;
 	*final_y = def_y;
     }
@@ -299,6 +301,7 @@
 	if (!ir) return;		/* outside icon regions, leave alone */
     }
 
+#ifdef NOTREACHED
     defx = -100;
     defy = -100;
     PlaceIcon(tmp_win, defx, defy, &x, &y);
@@ -310,6 +313,7 @@
 	MoveIcon(tmp_win, x, y);
 	tmp_win->icon_moved = FALSE;	/* since we've restored it */
     }
+#endif
 }
 
 static IconEntry *
