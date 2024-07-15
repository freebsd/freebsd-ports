--- afterstep/icons.c.orig	1997-03-21 00:09:21 UTC
+++ afterstep/icons.c
@@ -10,7 +10,7 @@
  *
  * Modifications: Copyright 1995 Bo Yang. No further restrictions,
  * as long as this copyright notice is preserved.
- * 
+ */
 /***********************************************************************
  *
  * afterstep icon code
@@ -779,10 +779,12 @@ void Iconify(ASWindow *tmp_win, int def_x, int def_y)
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
