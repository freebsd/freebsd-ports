--- programs/dtappbuilder/src/ab/pal_spinbox.c.orig	2023-02-15 07:51:51.805115000 -0800
+++ programs/dtappbuilder/src/ab/pal_spinbox.c	2023-02-15 07:53:12.123556000 -0800
@@ -293,9 +293,9 @@
         /* Spinbox Type */
         n = 0;
         item[n] = cgen->spinboxtype_rbox_items.Numeric_item;
-        item_ptr[n] = AB_TEXT_NUMERIC; n++;
+        item_ptr[n] = (void *) AB_TEXT_NUMERIC; n++;
         item[n] = cgen->spinboxtype_rbox_items.String_List_item;
-        item_ptr[n] = AB_TEXT_DEFINED_STRING; n++;
+        item_ptr[n] = (void *) AB_TEXT_DEFINED_STRING; n++;
         prop_radiobox_init(&(pss->spinbox_type), cgen->spinboxtype_rbox_label,
                        cgen->spinboxtype_rbox, n, item, item_ptr,
                        cgen->spinboxtype_cb);
@@ -306,9 +306,9 @@
         /* Label, Type, Position */
         n = 0;
         item[n] = cgen->labeltype_rbox_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->labeltype_rbox_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
         prop_options_init(&(pss->label_type), cgen->labeltype_rbox_label,
                 cgen->labeltype_rbox, cgen->labeltype_rbox_menu,
 		n, item, item_ptr,
@@ -321,9 +321,9 @@
 
         n = 0;
         item[n] = cgen->labelpos_rbox_items.Above_item;
-        item_ptr[n] = AB_CP_NORTH; n++;
+        item_ptr[n] = (void *) AB_CP_NORTH; n++;
         item[n] = cgen->labelpos_rbox_items.Left_item;
-        item_ptr[n] = AB_CP_WEST; n++;
+        item_ptr[n] = (void *) AB_CP_WEST; n++;
         prop_options_init(&(pss->label_pos), cgen->labeltype_rbox_label,
                 cgen->labelpos_rbox, cgen->labelpos_rbox_menu,
                 n, item, item_ptr,
@@ -332,15 +332,15 @@
 	/* Arrow Style */
         n = 0;
         item[n] = cgen->arrowstyle_opmenu_items.Flat_Beginning_item;
-        item_ptr[n] = AB_ARROW_FLAT_BEGIN; n++;
+        item_ptr[n] = (void *) AB_ARROW_FLAT_BEGIN; n++;
         item[n] = cgen->arrowstyle_opmenu_items.Flat_End_item;
-        item_ptr[n] = AB_ARROW_FLAT_END; n++;
+        item_ptr[n] = (void *) AB_ARROW_FLAT_END; n++;
         item[n] = cgen->arrowstyle_opmenu_items.Beginning_item;
-        item_ptr[n] = AB_ARROW_BEGIN; n++;
+        item_ptr[n] = (void *) AB_ARROW_BEGIN; n++;
         item[n] = cgen->arrowstyle_opmenu_items.End_item;
-        item_ptr[n] = AB_ARROW_END; n++;
+        item_ptr[n] = (void *) AB_ARROW_END; n++;
         item[n] = cgen->arrowstyle_opmenu_items.Split_item;
-        item_ptr[n] = AB_ARROW_SPLIT; n++;
+        item_ptr[n] = (void *) AB_ARROW_SPLIT; n++;
 	prop_options_init(&(pss->arrow_style), cgen->arrowstyle_opmenu_label,
 		cgen->arrowstyle_opmenu, cgen->arrowstyle_opmenu_menu,
 		n, item, item_ptr,
