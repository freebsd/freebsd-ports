$FreeBSD: /tmp/pcvs/ports/x11-wm/afterstep/files/patch-icons.c,v 1.1 2005-10-24 14:19:00 dinoex Exp $

--- afterstep/icons.c.orig	Thu Mar 20 19:09:21 1997
+++ afterstep/icons.c	Sun May 26 18:15:10 2002
@@ -779,10 +779,12 @@
 	}
     } 
 
-    if(tmp_win->flags & ICON_MOVED)
-      CreateIconWindow(tmp_win,tmp_win->icon_x_loc,tmp_win->icon_y_loc);
-    else
-      CreateIconWindow(tmp_win, def_x, def_y);
+    if(tmp_win->icon_pixmap_w == None) {
+      if(tmp_win->flags & ICON_MOVED)
+        CreateIconWindow(tmp_win,tmp_win->icon_x_loc,tmp_win->icon_y_loc);
+      else
+        CreateIconWindow(tmp_win, def_x, def_y);
+    }
 
   AutoPlace(tmp_win);
   tmp_win->flags |= ICONIFIED;
