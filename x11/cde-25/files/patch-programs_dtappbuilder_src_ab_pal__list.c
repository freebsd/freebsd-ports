--- programs/dtappbuilder/src/ab/pal_list.c.orig	2023-02-15 07:51:51.751859000 -0800
+++ programs/dtappbuilder/src/ab/pal_list.c	2023-02-15 07:53:12.110583000 -0800
@@ -307,9 +307,9 @@
         /* Label, Type, Position */
         n = 0;
         item[n] = cgen->labeltype_rbox_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->labeltype_rbox_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
         prop_options_init(&(pls->label_type), cgen->labeltype_rbox_label,
                 cgen->labeltype_rbox, cgen->labeltype_rbox_menu,
 		n, item, item_ptr,
@@ -322,9 +322,9 @@
 
         n = 0;
         item[n] = cgen->labelpos_rbox_items.Above_item;
-        item_ptr[n] = AB_CP_NORTH; n++;
+        item_ptr[n] = (void *) AB_CP_NORTH; n++;
         item[n] = cgen->labelpos_rbox_items.Left_item;
-        item_ptr[n] = AB_CP_WEST; n++;
+        item_ptr[n] = (void *) AB_CP_WEST; n++;
         prop_options_init(&(pls->label_pos), cgen->labelpos_rbox_label,
                 cgen->labelpos_rbox, cgen->labelpos_rbox_menu,
                 n, item, item_ptr,
@@ -333,13 +333,13 @@
         /* Selection Mode */
         n = 0;
         item[n] = cgen->selmode_rbox_items.Single_Select_item;
-        item_ptr[n] = AB_SELECT_SINGLE; n++;
+        item_ptr[n] = (void *) AB_SELECT_SINGLE; n++;
         item[n] = cgen->selmode_rbox_items.Browse_Select_item;
-        item_ptr[n] = AB_SELECT_BROWSE; n++;
+        item_ptr[n] = (void *) AB_SELECT_BROWSE; n++;
         item[n] = cgen->selmode_rbox_items.Multiple_Select_item;
-        item_ptr[n] = AB_SELECT_MULTIPLE; n++;
+        item_ptr[n] = (void *) AB_SELECT_MULTIPLE; n++;
         item[n] = cgen->selmode_rbox_items.Browse_Multiple_Select_item;
-        item_ptr[n] = AB_SELECT_BROWSE_MULTIPLE; n++;
+        item_ptr[n] = (void *) AB_SELECT_BROWSE_MULTIPLE; n++;
         prop_options_init(&(pls->sel_mode), cgen->selmode_rbox_label,
                                 cgen->selmode_rbox, cgen->selmode_rbox_menu,
                                 n, item, item_ptr,
@@ -355,9 +355,9 @@
 	/* Width */
         n = 0;
         item[n] = cgen->wpolicy_rbox_items.Longest_Item_item;
-        item_ptr[n] = SIZE_OF_CONTENTS_KEY; n++;
+        item_ptr[n] = (void *) SIZE_OF_CONTENTS_KEY; n++;
         item[n] = cgen->wpolicy_rbox_items.Fixed_item;
-        item_ptr[n] = SIZE_FIXED_KEY; n++;
+        item_ptr[n] = (void *) SIZE_FIXED_KEY; n++;
         prop_radiobox_init(&(pls->wth_policy), cgen->wpolicy_rbox_label,
                 cgen->wpolicy_rbox, n, item, item_ptr,
                 cgen->wpolicy_cb);
@@ -381,9 +381,9 @@
 
 	n = 0;
 	item[n] = cgen->hgt_opmenu_items.Lines_item;
-	item_ptr[n] = SIZE_IN_CHARS_KEY; n++;
+	item_ptr[n] = (void *) SIZE_IN_CHARS_KEY; n++;
 	item[n] = cgen->hgt_opmenu_items.Pixels_item;
-	item_ptr[n] = SIZE_IN_PIXELS_KEY; n++;
+	item_ptr[n] = (void *) SIZE_IN_PIXELS_KEY; n++;
 	prop_options_init(&(pls->hgt_metric), cgen->hgt_opmenu_label,
 			   cgen->hgt_opmenu,
 			   cgen->hgt_opmenu_menu,
