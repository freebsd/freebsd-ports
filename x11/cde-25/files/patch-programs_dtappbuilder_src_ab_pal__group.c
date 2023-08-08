--- programs/dtappbuilder/src/ab/pal_group.c.orig	2023-02-15 07:51:51.808648000 -0800
+++ programs/dtappbuilder/src/ab/pal_group.c	2023-02-15 07:53:12.127044000 -0800
@@ -742,15 +742,15 @@
 	/* Border Frame Setting */
 	n = 0;
 	item[n] = cgen->bframe_opmenu_items.None_item;
-	item_ptr[n] = AB_LINE_NONE; n++;
+	item_ptr[n] = (void *) AB_LINE_NONE; n++;
 	item[n] = cgen->bframe_opmenu_items.Shadow_Out_item;
-	item_ptr[n] = AB_LINE_SHADOW_OUT; n++;
+	item_ptr[n] = (void *) AB_LINE_SHADOW_OUT; n++;
 	item[n] = cgen->bframe_opmenu_items.Shadow_In_item;
-	item_ptr[n] = AB_LINE_SHADOW_IN; n++;
+	item_ptr[n] = (void *) AB_LINE_SHADOW_IN; n++;
 	item[n] = cgen->bframe_opmenu_items.Etched_Out_item;
-	item_ptr[n] = AB_LINE_ETCHED_OUT; n++;
+	item_ptr[n] = (void *) AB_LINE_ETCHED_OUT; n++;
 	item[n] = cgen->bframe_opmenu_items.Etched_In_item;
-	item_ptr[n] = AB_LINE_ETCHED_IN; n++;
+	item_ptr[n] = (void *) AB_LINE_ETCHED_IN; n++;
 	prop_options_init(&(pgs->frame), cgen->bframe_opmenu_label,
 			    cgen->bframe_opmenu, cgen->bframe_opmenu_menu,
 			    n, item, item_ptr,
@@ -759,13 +759,13 @@
 	/* Layout Type */
         n = 0;
         item[n] = cgen->layout_rbox_items.bitmaps_ggp_as_is_xbm_item;
-        item_ptr[n] = AB_GROUP_IGNORE; n++;
+        item_ptr[n] = (void *) AB_GROUP_IGNORE; n++;
         item[n] = cgen->layout_rbox_items.bitmaps_ggp_col_xbm_item;
-        item_ptr[n] = AB_GROUP_COLUMNS; n++;
+        item_ptr[n] = (void *) AB_GROUP_COLUMNS; n++;
         item[n] = cgen->layout_rbox_items.bitmaps_ggp_row_xbm_item;
-        item_ptr[n] = AB_GROUP_ROWS; n++;
+        item_ptr[n] = (void *) AB_GROUP_ROWS; n++;
         item[n] = cgen->layout_rbox_items.bitmaps_ggp_rowcol_xbm_item;
-        item_ptr[n] = AB_GROUP_ROWSCOLUMNS; n++;
+        item_ptr[n] = (void *) AB_GROUP_ROWSCOLUMNS; n++;
 	prop_radiobox_init(&(pgs->layout_type), cgen->layout_rbox_label,
 			cgen->layout_rbox, n, item, item_ptr,
 			cgen->layout_cb1);
@@ -781,9 +781,9 @@
 	/* Grid Row/Columns */
         n = 0;
         item[n] = cgen->gridrowcol_rbox_items.Rows_item;
-        item_ptr[n] = AB_ORIENT_HORIZONTAL; n++;
+        item_ptr[n] = (void *) AB_ORIENT_HORIZONTAL; n++;
         item[n] = cgen->gridrowcol_rbox_items.Columns_item;
-        item_ptr[n] = AB_ORIENT_VERTICAL; n++;
+        item_ptr[n] = (void *) AB_ORIENT_VERTICAL; n++;
 	prop_radiobox_init(&(pgs->grid_rowcol), NULL,
 			cgen->gridrowcol_rbox, n, item, item_ptr,
 			cgen->gridrowcol_cb);
@@ -795,13 +795,13 @@
         /* Vertical Alignment */
         n = 0;
         item[n] = cgen->valign_opmenu_items.bitmaps_align_left_xbm_item;
-        item_ptr[n] = AB_ALIGN_LEFT; n++;
+        item_ptr[n] = (void *) AB_ALIGN_LEFT; n++;
         item[n] = cgen->valign_opmenu_items.bitmaps_align_labels_xbm_item;
-        item_ptr[n] = AB_ALIGN_LABELS; n++;
+        item_ptr[n] = (void *) AB_ALIGN_LABELS; n++;
         item[n] = cgen->valign_opmenu_items.bitmaps_align_vcenter_xbm_item;
-        item_ptr[n] = AB_ALIGN_VCENTER; n++;
+        item_ptr[n] = (void *) AB_ALIGN_VCENTER; n++;
         item[n] = cgen->valign_opmenu_items.bitmaps_align_right_xbm_item;
-        item_ptr[n] = AB_ALIGN_RIGHT; n++;
+        item_ptr[n] = (void *) AB_ALIGN_RIGHT; n++;
 	prop_options_init(&(pgs->valign), cgen->valign_opmenu_label,
 			    cgen->valign_opmenu, cgen->valign_opmenu_menu,
 			    n, item, item_ptr,
@@ -814,11 +814,11 @@
         /* Horizontal Alignment */
         n = 0;
         item[n] = cgen->halign_opmenu_items.bitmaps_align_top_xbm_item;
-        item_ptr[n] = AB_ALIGN_TOP; n++;
+        item_ptr[n] = (void *) AB_ALIGN_TOP; n++;
         item[n] = cgen->halign_opmenu_items.bitmaps_align_hcenter_xbm_item;
-        item_ptr[n] = AB_ALIGN_HCENTER; n++;
+        item_ptr[n] = (void *) AB_ALIGN_HCENTER; n++;
         item[n] = cgen->halign_opmenu_items.bitmaps_align_bottom_xbm_item;
-        item_ptr[n] = AB_ALIGN_BOTTOM; n++;
+        item_ptr[n] = (void *) AB_ALIGN_BOTTOM; n++;
 	prop_options_init(&(pgs->halign), cgen->halign_opmenu_label,
 			    cgen->halign_opmenu, cgen->halign_opmenu_menu,
 			    n, item, item_ptr,
