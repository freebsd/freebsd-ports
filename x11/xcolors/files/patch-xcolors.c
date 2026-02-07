--- xcolors.c.orig	1994-06-07 19:08:19.000000000 +0200
+++ xcolors.c	2011-07-05 12:16:57.000000000 +0200
@@ -315,7 +315,7 @@
 	    }
 	    if (save_colorname[0] != '\0') /* skip first time through */
 	      if (!do_color(parent, save_colorname))
-		return;
+		return 0;
 	    prev_r = r;
 	    prev_g = g;
 	    prev_b = b;
