--- programs/dtappbuilder/src/ab/pal_choice.c.orig	2023-02-15 07:51:51.747764000 -0800
+++ programs/dtappbuilder/src/ab/pal_choice.c	2023-02-15 07:53:12.108230000 -0800
@@ -343,9 +343,9 @@
         /* Label, Type, Position */
         n = 0;
         item[n] = cgen->labeltype_rbox_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->labeltype_rbox_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
         prop_options_init(&(pcs->label_type), cgen->labeltype_rbox_label,
                 cgen->labeltype_rbox, cgen->labeltype_rbox_menu,
 		n, item, item_ptr, cgen->labeltype_cb);
@@ -357,9 +357,9 @@
 
         n = 0;
         item[n] = cgen->labelpos_rbox_items.Above_item;
-        item_ptr[n] = AB_CP_NORTH; n++;
+        item_ptr[n] = (void *) AB_CP_NORTH; n++;
         item[n] = cgen->labelpos_rbox_items.Left_item;
-        item_ptr[n] = AB_CP_WEST; n++;
+        item_ptr[n] = (void *) AB_CP_WEST; n++;
         prop_options_init(&(pcs->label_pos), cgen->labelpos_rbox_label,
                 cgen->labelpos_rbox, cgen->labelpos_rbox_menu,
                 n, item, item_ptr, cgen->labeltype_cb);
@@ -368,11 +368,11 @@
         /* Choice Type */
         n = 0;
         item[n] = cgen->choicetype_rbox_items.Radio_Box_item;
-        item_ptr[n] = AB_CHOICE_EXCLUSIVE; n++;
+        item_ptr[n] = (void *) AB_CHOICE_EXCLUSIVE; n++;
         item[n] = cgen->choicetype_rbox_items.Check_Box_item;
-        item_ptr[n] = AB_CHOICE_NONEXCLUSIVE; n++;
+        item_ptr[n] = (void *) AB_CHOICE_NONEXCLUSIVE; n++;
         item[n] = cgen->choicetype_rbox_items.Option_Menu_item;
-        item_ptr[n] = AB_CHOICE_OPTION_MENU; n++;
+        item_ptr[n] = (void *) AB_CHOICE_OPTION_MENU; n++;
         prop_options_init(&(pcs->choice_type), cgen->choicetype_rbox_label,
                         cgen->choicetype_rbox, cgen->choicetype_rbox_menu,
                         n, item, item_ptr,
@@ -384,9 +384,9 @@
 	/* Rows/Columns */
         n = 0;
         item[n] = cgen->layout_rbox_items.Columns_item;
-        item_ptr[n] = AB_ORIENT_VERTICAL; n++;
+        item_ptr[n] = (void *) AB_ORIENT_VERTICAL; n++;
         item[n] = cgen->layout_rbox_items.Rows_item;
-        item_ptr[n] = AB_ORIENT_HORIZONTAL; n++;
+        item_ptr[n] = (void *) AB_ORIENT_HORIZONTAL; n++;
         prop_radiobox_init(&(pcs->row_col), cgen->layout_rbox_label,
                 cgen->layout_rbox,
                 n, item, item_ptr,
@@ -428,9 +428,9 @@
 	/* Item Label Type */
         n = 0;
         item[n] = cgen->itemlabel_opmenu_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->itemlabel_opmenu_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
         prop_options_init(&(pcs->item_label_type), cgen->itemlabel_type_label,
                 cgen->itemlabel_opmenu, cgen->itemlabel_opmenu_menu,
 		n, item, item_ptr, cgen->itemlist_cb);
