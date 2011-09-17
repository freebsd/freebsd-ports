--- src/itask_items.c.orig	2011-09-16 17:25:41.087552558 +0200
+++ src/itask_items.c	2011-09-16 17:26:24.411276478 +0200
@@ -114,7 +114,7 @@
      {
 	ic = _itask_items_find_item(it, ev->border);
 	if (!ic)
-	  return;
+	  return NULL;
 
 	itask_item_remove(ic);
 	itask_item_swap_youngest_from_menu(it);