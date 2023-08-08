--- programs/dtappbuilder/src/ab/pal_sep.c.orig	2023-02-15 07:51:51.803847000 -0800
+++ programs/dtappbuilder/src/ab/pal_sep.c	2023-02-15 07:53:12.121235000 -0800
@@ -255,9 +255,9 @@
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
@@ -265,23 +265,23 @@
         /* Line Style */
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
         prop_options_init(&(pss->line_style), cgen->linestyle_opmenu_label,
                 cgen->linestyle_opmenu, cgen->linestyle_opmenu_menu,
                 n, item, item_ptr,
