--- lib/libxview/textsw/ev_edit.c.orig	Sun Oct  5 00:21:31 2003
+++ lib/libxview/textsw/ev_edit.c	Sun Oct  5 00:23:36 2003
@@ -123,7 +123,7 @@
 	    ft_add_delta(*table, 0, delta);
 	} else {
 	    lt_index = ft_bounding_index(table, before_edit);
-	    if (lt_index < table->last_plus_one)
+	    if (lt_index+1 < table->last_plus_one)
 		ft_add_delta(*table, lt_index + 1, delta);
 	}
     } else {
