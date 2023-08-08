--- programs/dtappbuilder/src/ab/pal_textf.c.orig	2023-02-15 07:51:51.748487000 -0800
+++ programs/dtappbuilder/src/ab/pal_textf.c	2023-02-15 07:53:12.109292000 -0800
@@ -259,9 +259,9 @@
         /* Label, Type, Position */
         n = 0;
         item[n] = cgen->labeltype_rbox_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->labeltype_rbox_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
         prop_options_init(&(pts->label_type), cgen->labeltype_rbox_label,
                         cgen->labeltype_rbox, cgen->labeltype_rbox_menu,
 			n, item, item_ptr,
@@ -273,9 +273,9 @@
 
         n = 0;
         item[n] = cgen->labelpos_rbox_items.Left_item;
-        item_ptr[n] = AB_CP_WEST; n++;
+        item_ptr[n] = (void *) AB_CP_WEST; n++;
         item[n] = cgen->labelpos_rbox_items.Above_item;
-        item_ptr[n] = AB_CP_NORTH; n++;
+        item_ptr[n] = (void *) AB_CP_NORTH; n++;
         prop_options_init(&(pts->label_pos), cgen->labelpos_rbox_label,
                         cgen->labelpos_rbox, cgen->labelpos_rbox_menu,
                         n, item, item_ptr,
@@ -291,9 +291,9 @@
         /* Operation */
         n = 0;
         item[n] = cgen->op_rbox_items.Editable_item;
-        item_ptr[n] = False; n++;
+        item_ptr[n] = (void *) False; n++;
         item[n] = cgen->op_rbox_items.Read_Only_item;
-        item_ptr[n] = True; n++;
+        item_ptr[n] = (void *) True; n++;
         prop_radiobox_init(&(pts->op), cgen->op_rbox_label,
                 cgen->op_rbox, n, item, item_ptr,
                 cgen->op_cb);
@@ -322,9 +322,9 @@
 
 	n = 0;
 	item[n] = cgen->width_opmenu_items.Characters_item;
-	item_ptr[n] = SIZE_IN_CHARS_KEY; n++;
+	item_ptr[n] = (void *) SIZE_IN_CHARS_KEY; n++;
 	item[n] = cgen->width_opmenu_items.Pixels_item;
-	item_ptr[n] = SIZE_IN_PIXELS_KEY; n++;
+	item_ptr[n] = (void *) SIZE_IN_PIXELS_KEY; n++;
 	prop_options_init(&(pts->size_metric), cgen->width_opmenu_label,
 			   cgen->width_opmenu,
 			   cgen->width_opmenu_menu,
