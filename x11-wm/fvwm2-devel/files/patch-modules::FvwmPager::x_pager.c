--- modules/FvwmPager/x_pager.c.old	Thu Oct 24 00:46:59 2002
+++ modules/FvwmPager/x_pager.c	Fri Nov  1 19:26:11 2002
@@ -1630,8 +1630,8 @@
 				XDrawLine(
 					dpy,Desks[desk].w,Desks[desk].DashedGC,
 					x1,y1,x1,y2);
-				x += Scr.MyDisplayWidth;
 			}
+			x += Scr.MyDisplayWidth;
 		}
 		y = Scr.MyDisplayHeight;
 		x1 = 0;
@@ -1640,9 +1640,11 @@
 		{
 			y1 = (y * desk_h) / Scr.VHeight;
 			if (!use_no_separators)
+			{
 				XDrawLine(
 					dpy,Desks[desk].w,Desks[desk].DashedGC,
 					x1,y1,x2,y1);
+			}
 			y += Scr.MyDisplayHeight;
 		}
 	}
