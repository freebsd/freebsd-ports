--- programs/dtappbuilder/src/ab/pal_combobox.c.orig	2023-02-15 07:51:51.783082000 -0800
+++ programs/dtappbuilder/src/ab/pal_combobox.c	2023-02-15 07:53:12.117530000 -0800
@@ -295,9 +295,9 @@
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
 			n, item, item_ptr,
@@ -310,9 +310,9 @@
 
         n = 0;
         item[n] = cgen->labelpos_rbox_items.Above_item;
-        item_ptr[n] = AB_CP_NORTH; n++;
+        item_ptr[n] = (void *) AB_CP_NORTH; n++;
         item[n] = cgen->labelpos_rbox_items.Left_item;
-        item_ptr[n] = AB_CP_WEST; n++;
+        item_ptr[n] = (void *) AB_CP_WEST; n++;
         prop_options_init(&(pcs->label_pos), cgen->labelpos_rbox_label,
                 	cgen->labelpos_rbox, cgen->labelpos_rbox_menu,
                     n, item, item_ptr,
@@ -321,9 +321,9 @@
         /* Read Only */
         n = 0;
         item[n] = cgen->comboboxtype_rbox_items.Static_item;
-        item_ptr[n] = True; n++;
+        item_ptr[n] = (void *) True; n++;
         item[n] = cgen->comboboxtype_rbox_items.Editable_item;
-        item_ptr[n] = False; n++;
+        item_ptr[n] = (void *) False; n++;
         prop_radiobox_init(&(pcs->combobox_type), cgen->comboboxtype_rbox_label,
                        cgen->comboboxtype_rbox, n, item, item_ptr,
                        cgen->comboboxtype_cb);
@@ -339,9 +339,9 @@
 	/* Width */
         n = 0;
         item[n] = cgen->wpolicy_rbox_items.Longest_Item_item;
-        item_ptr[n] = SIZE_OF_CONTENTS_KEY; n++;
+        item_ptr[n] = (void *) SIZE_OF_CONTENTS_KEY; n++;
         item[n] = cgen->wpolicy_rbox_items.Fixed_item;
-        item_ptr[n] = SIZE_FIXED_KEY; n++;
+        item_ptr[n] = (void *) SIZE_FIXED_KEY; n++;
         prop_radiobox_init(&(pcs->wth_policy), cgen->wpolicy_rbox_label,
                 cgen->wpolicy_rbox, n, item, item_ptr,
                 cgen->wpolicy_cb);
