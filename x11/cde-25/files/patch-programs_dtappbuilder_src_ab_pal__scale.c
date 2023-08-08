--- programs/dtappbuilder/src/ab/pal_scale.c.orig	2023-02-15 07:51:51.776871000 -0800
+++ programs/dtappbuilder/src/ab/pal_scale.c	2023-02-15 07:53:12.116478000 -0800
@@ -292,9 +292,9 @@
         /* Label, Type, Position */
         n = 0;
         item[n] = cgen->labeltype_opmenu_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->labeltype_opmenu_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
         prop_options_init(&(pss->label_type), cgen->labeltype_opmenu_label,
                         cgen->labeltype_opmenu,
                         cgen->labeltype_opmenu_menu,
@@ -308,9 +308,9 @@
  
         n = 0;
         item[n] = cgen->labelpos_opmenu_items.Left_item;
-        item_ptr[n] = AB_CP_WEST; n++;
+        item_ptr[n] = (void *) AB_CP_WEST; n++;
         item[n] = cgen->labelpos_opmenu_items.Above_item;
-        item_ptr[n] = AB_CP_NORTH; n++;
+        item_ptr[n] = (void *) AB_CP_NORTH; n++;
         prop_options_init(&(pss->label_pos), cgen->labelpos_opmenu_label,
                         cgen->labelpos_opmenu,
                         cgen->labelpos_opmenu_menu,
@@ -320,9 +320,9 @@
         /* Scale Type */
         n = 0;
         item[n] = cgen->scaletype_rbox_items.Scale_item;
-        item_ptr[n] = False; n++;
+        item_ptr[n] = (void *) False; n++;
         item[n] = cgen->scaletype_rbox_items.Gauge_item;
-        item_ptr[n] = True; n++;
+        item_ptr[n] = (void *) True; n++;
         prop_radiobox_init(&(pss->scale_type), cgen->scaletype_rbox_label,
                                 cgen->scaletype_rbox, n, item, item_ptr,
                                 cgen->scaletype_cb);
@@ -338,9 +338,9 @@
         /* Orientation */
         n = 0;
         item[n] = cgen->orient_rbox_items.Horizontal_item;
-        item_ptr[n] = AB_ORIENT_HORIZONTAL; n++;
+        item_ptr[n] = (void *) AB_ORIENT_HORIZONTAL; n++;
         item[n] = cgen->orient_rbox_items.Vertical_item;
-        item_ptr[n] = AB_ORIENT_VERTICAL; n++;
+        item_ptr[n] = (void *) AB_ORIENT_VERTICAL; n++;
         prop_radiobox_init(&(pss->orient), cgen->orient_rbox_label,
                                 cgen->orient_rbox, n, item, item_ptr,
                                 cgen->orient_cb);
@@ -352,13 +352,13 @@
         /* Direction */
         n = 0;
         item[n] = cgen->dir_opmenu_items.Left_to_Right_item;
-        item_ptr[n] = AB_DIR_LEFT_TO_RIGHT; n++;
+        item_ptr[n] = (void *) AB_DIR_LEFT_TO_RIGHT; n++;
         item[n] = cgen->dir_opmenu_items.Right_to_Left_item;
-        item_ptr[n] = AB_DIR_RIGHT_TO_LEFT; n++;
+        item_ptr[n] = (void *) AB_DIR_RIGHT_TO_LEFT; n++;
         item[n] = cgen->dir_opmenu_items.Top_to_Bottom_item;
-        item_ptr[n] = AB_DIR_TOP_TO_BOTTOM; n++;
+        item_ptr[n] = (void *) AB_DIR_TOP_TO_BOTTOM; n++;
         item[n] = cgen->dir_opmenu_items.Bottom_to_Top_item;
-        item_ptr[n] = AB_DIR_BOTTOM_TO_TOP; n++;
+        item_ptr[n] = (void *) AB_DIR_BOTTOM_TO_TOP; n++;
         prop_options_init(&(pss->dir), cgen->dir_opmenu_label,
                 cgen->dir_opmenu, cgen->dir_opmenu_menu,
                 n, item, item_ptr,
