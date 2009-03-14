--- ./fvwm/icons.c.orig	1994-11-15 14:03:29.000000000 +0000
+++ ./fvwm/icons.c	2009-03-11 09:42:52.000000000 +0000
@@ -340,7 +340,7 @@
   if(Tmp_win->flags & SUPPRESSICON)
     return;
 
-  if (Tmp_win->icon_w == (int)NULL)
+  if (Tmp_win->icon_w == 0)
     return;
   
   Tmp_win->icon_t_width = XTextWidth(IconFont->font,Tmp_win->icon_name, 
