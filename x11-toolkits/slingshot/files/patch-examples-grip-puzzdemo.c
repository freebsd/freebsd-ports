--- examples/grip/puzzdemo.c.orig	1993-10-25 16:39:39.000000000 -0700
+++ examples/grip/puzzdemo.c	2013-09-17 08:44:03.422374693 -0700
@@ -628,7 +628,7 @@
 	  for (x=0; x< N_HORI; x++)
 		if(xv_get(puzzle_tile, ARRAY_TILE_POSITION, x, y) !=
 		   get_solved_piece(x, y))
-			return;
+			return 0;
 	xv_set(frame, 
 		FRAME_LEFT_FOOTER, "Congratulations!",
 		NULL);
