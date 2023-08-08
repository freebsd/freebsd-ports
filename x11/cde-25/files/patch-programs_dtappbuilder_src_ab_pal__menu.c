--- programs/dtappbuilder/src/ab/pal_menu.c.orig	2023-02-15 07:51:51.765338000 -0800
+++ programs/dtappbuilder/src/ab/pal_menu.c	2023-02-15 07:53:12.111874000 -0800
@@ -339,9 +339,9 @@
         /* Tear-off */
         n = 0;
         item[n] = cgen->tearoff_rbox_items.Enabled_item;
-        item_ptr[n] = True; n++;
+        item_ptr[n] = (void *) True; n++;
         item[n] = cgen->tearoff_rbox_items.Disabled_item;
-        item_ptr[n] = False; n++;
+        item_ptr[n] = (void *) False; n++;
         prop_radiobox_init(&(pms->tearoff), cgen->tearoff_rbox_label,
                 cgen->tearoff_rbox, n, item, item_ptr,
                 cgen->tearoff_cb);
@@ -368,11 +368,11 @@
                 cgen->itemlabel_field, cgen->itemlist_cb);
         n = 0;
         item[n] = cgen->itemlabeltype_opmenu_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->itemlabeltype_opmenu_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
 	item[n] = cgen->itemlabeltype_opmenu_items.Separator_item;
-        item_ptr[n] = AB_LABEL_SEPARATOR; n++;
+        item_ptr[n] = (void *) AB_LABEL_SEPARATOR; n++;
         prop_options_init(&(pms->item_label_type), cgen->itemlabeltype_opmenu_label,
                 cgen->itemlabeltype_opmenu, cgen->itemlabeltype_opmenu_menu,
                 n, item, item_ptr, cgen->itemlist_cb);
@@ -392,23 +392,23 @@
 	/* Item Line Style */
         n = 0;
         item[n] = cgen->linestyle_opmenu_items.None_item;
-        item_ptr[n] = AB_LINE_NONE; n++;
+        item_ptr[n] = (void *) AB_LINE_NONE; n++;
         item[n] = cgen->linestyle_opmenu_items.Etched_In_item;
-        item_ptr[n] = AB_LINE_ETCHED_IN; n++;
+        item_ptr[n] = (void *) AB_LINE_ETCHED_IN; n++;
         item[n] = cgen->linestyle_opmenu_items.Etched_Out_item;
-        item_ptr[n] = AB_LINE_ETCHED_OUT; n++;
+        item_ptr[n] = (void *) AB_LINE_ETCHED_OUT; n++;
         item[n] = cgen->linestyle_opmenu_items.Etched_In_Dash_item;
-        item_ptr[n] = AB_LINE_ETCHED_IN_DASH; n++;
+        item_ptr[n] = (void *) AB_LINE_ETCHED_IN_DASH; n++;
         item[n] = cgen->linestyle_opmenu_items.Etched_Out_Dash_item;
-        item_ptr[n] = AB_LINE_ETCHED_OUT_DASH; n++;
+        item_ptr[n] = (void *) AB_LINE_ETCHED_OUT_DASH; n++;
         item[n] = cgen->linestyle_opmenu_items.Single_Line_item;
-        item_ptr[n] = AB_LINE_SINGLE_LINE; n++;
+        item_ptr[n] = (void *) AB_LINE_SINGLE_LINE; n++;
         item[n] = cgen->linestyle_opmenu_items.Double_Line_item;
-        item_ptr[n] = AB_LINE_DOUBLE_LINE; n++;
+        item_ptr[n] = (void *) AB_LINE_DOUBLE_LINE; n++;
         item[n] = cgen->linestyle_opmenu_items.Single_Dashed_Line_item;
-        item_ptr[n] = AB_LINE_SINGLE_DASHED_LINE; n++;
+        item_ptr[n] = (void *) AB_LINE_SINGLE_DASHED_LINE; n++;
         item[n] = cgen->linestyle_opmenu_items.Double_Dashed_Line_item;
-        item_ptr[n] = AB_LINE_DOUBLE_DASHED_LINE; n++;
+        item_ptr[n] = (void *) AB_LINE_DOUBLE_DASHED_LINE; n++;
         prop_options_init(&(pms->item_line_style), cgen->linestyle_opmenu_label,
                 cgen->linestyle_opmenu, cgen->linestyle_opmenu_menu,
                 n, item, item_ptr,
