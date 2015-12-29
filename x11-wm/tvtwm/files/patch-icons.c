--- icons.c.orig	1995-02-03 00:37:34 UTC
+++ icons.c
@@ -233,10 +233,12 @@ int *final_x, *final_y;
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
@@ -299,6 +301,7 @@ IconUp (tmp_win)
 	if (!ir) return;		/* outside icon regions, leave alone */
     }
 
+#ifdef NOTREACHED
     defx = -100;
     defy = -100;
     PlaceIcon(tmp_win, defx, defy, &x, &y);
@@ -310,6 +313,7 @@ IconUp (tmp_win)
 	MoveIcon(tmp_win, x, y);
 	tmp_win->icon_moved = FALSE;	/* since we've restored it */
     }
+#endif
 }
 
 static IconEntry *
