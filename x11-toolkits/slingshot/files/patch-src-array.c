--- src/array.c.orig	1993-10-25 11:41:21.000000000 -0700
+++ src/array.c	2013-09-17 08:42:27.922294229 -0700
@@ -712,10 +712,10 @@
 	int		previously_unmanaged;
 	
 	if(!child)
-		return;
+		return 0;
 	layout_data = get_layout_data(child);
 	if(!layout_data)
-		return;
+		return 0;
 
 	previously_unmanaged = FLAG_IS_SET(layout_data->cflags, CF_UNMANAGED);
 
@@ -729,7 +729,7 @@
 			array_tile_unmanage_child(ainfo, child);
 			array_tile_shrink(array_tile, child);
 			rectobj_repaint_rect(child, NULL, TRUE);
-			return;
+			return 0;
 		}
 		layout_data->column = column;
 	}
@@ -739,7 +739,7 @@
 			array_tile_unmanage_child(ainfo, child);
 			array_tile_shrink(array_tile, child);
 			rectobj_repaint_rect(child, NULL, TRUE);
-			return;
+			return 0;
 		}
 		layout_data->row = row;
 	}
